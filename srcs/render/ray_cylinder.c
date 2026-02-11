/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:25 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/11 20:57:10 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	update_nearest_hit(t_hit *hit, double t, t_vec3 normal)
{
	if (t >= hit->distance)
		return ;
	hit->distance = t;
	hit->normal = normal;
}

static void	get_quadratic_coeffs(t_ray ray, const t_cylinder *cy, double *a,
		double *b, double *c)
{
	t_vec3	oc;
	double	dot_dir_axis;
	double	dot_oc_axis;
	double	radius;

	oc = vec3_sub(ray.origin, cy->center);
	dot_dir_axis = vec3_dot(ray.direction, cy->axis);
	dot_oc_axis = vec3_dot(oc, cy->axis);
	radius = cy->diameter * 0.5;
	*a = vec3_dot(ray.direction, ray.direction) - dot_dir_axis * dot_dir_axis;
	*b = 2.0 * (vec3_dot(ray.direction, oc) - dot_dir_axis * dot_oc_axis);
	*c = vec3_dot(oc, oc) - dot_oc_axis * dot_oc_axis - radius * radius;
}

static void	try_update_nearest_hit(t_ray ray, t_cylinder *cy, t_hit *hit,
		double t)
{
	t_vec3	point;
	double	dot;
	double	cy_half_h;
	t_vec3	normal;

	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	dot = vec3_dot(vec3_sub(point, cy->center), cy->axis);
	cy_half_h = cy->height * 0.5;
	if (dot < -cy_half_h || dot > cy_half_h)
		return ;
	normal = vec3_sub(vec3_sub(point, cy->center), vec3_mul(cy->axis, dot));
	normal = vec3_normalize(normal);
	normal = front_normal(normal, ray.direction);
	update_nearest_hit(hit, t, normal);
}

static void	find_side_intersection(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	t;

	get_quadratic_coeffs(ray, cy, &a, &b, &c);
	if (fabs(a) < EPSILON)
		return ;
	disc = b * b - 4.0 * a * c;
	if (disc < 0.0)
		return ;
	t = (-b - sqrt(disc)) / (2.0 * a);
	if (t > EPSILON)
	{
		try_update_nearest_hit(ray, cy, hit, t);
		return ;
	}
	t = (-b + sqrt(disc)) / (2.0 * a);
	if (t > EPSILON)
		try_update_nearest_hit(ray, cy, hit, t);
}

static void	find_cap_intersection(t_ray ray, t_vec3 cap_center,
		t_vec3 cap_normal, double radius, t_hit *hit)
{
	double	denom;
	double	t;
	t_vec3	point;
	t_vec3	normal;
	t_vec3	d;

	denom = vec3_dot(ray.direction, cap_normal);
	if (fabs(denom) < EPSILON)
		return ;
	t = vec3_dot(vec3_sub(cap_center, ray.origin), cap_normal) / denom;
	if (t <= EPSILON || t >= hit->distance)
		return ;
	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	d = vec3_sub(point, cap_center);
	if (vec3_dot(d, d) > radius * radius)
		return ;
	normal = front_normal(cap_normal, ray.direction);
	update_nearest_hit(hit, t, normal);
}

int	calculate_cylinder_hit(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	double	radius;
	t_vec3	top_center;
	t_vec3	bottom_center;

	if (!cy || !hit)
		return (0);
	radius = cy->diameter * 0.5;
	hit->distance = DBL_MAX;
	find_side_intersection(ray, cy, hit);
	top_center = vec3_add(cy->center, vec3_mul(cy->axis, cy->height * 0.5));
	bottom_center = vec3_add(cy->center, vec3_mul(cy->axis, -(cy->height
					* 0.5)));
	find_cap_intersection(ray, top_center, cy->axis, radius, hit);
	find_cap_intersection(ray, bottom_center, vec3_mul(cy->axis, -1.0), radius,
		hit);
	if (hit->distance == DBL_MAX)
		return (0);
	return (1);
}
