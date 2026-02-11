/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:25 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/11 22:39:52 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	update_nearest_hit(t_hit *hit, double t, t_vec3 normal)
{
	if (t <= EPSILON || t >= hit->distance)
		return ;
	hit->distance = t;
	hit->normal = normal;
}

static void	try_update_nearest_hit(t_ray ray, t_cy_ctx *c, t_hit *hit, double t)
{
	t_vec3	point;
	double	dot;
	t_vec3	normal;

	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	dot = vec3_dot(vec3_sub(point, c->cy->center), c->cy->axis);
	if (dot < -c->half_h || dot > c->half_h)
		return ;
	normal = vec3_sub(vec3_sub(point, c->cy->center), vec3_mul(c->cy->axis,
				dot));
	normal = vec3_normalize(normal);
	update_nearest_hit(hit, t, front_normal(normal, ray.direction));
}

static void	find_cylinder_side_hit(t_ray ray, t_cy_ctx *c, t_hit *hit)
{
	t_vec3	oc;
	double	dot_dir_axis;
	double	dot_oc_axis;
	t_quad	q;
	double	t0;
	double	t1;

	oc = vec3_sub(ray.origin, c->cy->center);
	dot_dir_axis = vec3_dot(ray.direction, c->cy->axis);
	dot_oc_axis = vec3_dot(oc, c->cy->axis);
	q.a = vec3_dot(ray.direction, ray.direction) - dot_dir_axis * dot_dir_axis;
	q.b = 2.0 * (vec3_dot(ray.direction, oc) - dot_dir_axis * dot_oc_axis);
	q.c = vec3_dot(oc, oc) - dot_oc_axis * dot_oc_axis - c->radius * c->radius;
	if (fabs(q.a) <= EPSILON)
		return ;
	q.disc = q.b * q.b - 4.0 * q.a * q.c;
	if (q.disc < 0.0)
		return ;
	quad_roots(&q, &t0, &t1);
	if (t0 > EPSILON)
		try_update_nearest_hit(ray, c, hit, t0);
	if (t1 > EPSILON)
		try_update_nearest_hit(ray, c, hit, t1);
}

static void	find_cylinder_cap_hit(t_ray ray, t_vec3 cap_center,
		t_vec3 cap_normal, double radius, t_hit *hit)
{
	double	t;
	t_vec3	point;
	t_vec3	normal;
	t_vec3	d;

	t = find_plane_hit_t(ray, cap_center, cap_normal);
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
	t_cy_ctx	c;
	t_vec3		top_center;
	t_vec3		bottom_center;

	if (!cy || !hit)
		return (0);
	c.cy = cy;
	c.radius = cy->diameter * 0.5;
	c.half_h = cy->height * 0.5;
	hit->distance = DBL_MAX;
	find_cylinder_side_hit(ray, &c, hit);
	top_center = vec3_add(cy->center, vec3_mul(cy->axis, c.half_h));
	bottom_center = vec3_add(cy->center, vec3_mul(cy->axis, -(c.half_h)));
	find_cylinder_cap_hit(ray, top_center, cy->axis, c.radius, hit);
	find_cylinder_cap_hit(ray, bottom_center, vec3_mul(cy->axis, -1.0),
		c.radius, hit);
	if (hit->distance == DBL_MAX)
		return (0);
	return (1);
}
