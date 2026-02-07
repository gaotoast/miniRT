/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:25 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/30 14:35:40 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <float.h>

static void	update_best(double t, t_vec3 normal,
			double *best_distance, t_vec3 *best_normal, int *hit)
{
	if (t <= EPSILON || t >= *best_distance)
		return ;
	*best_distance = t;
	*best_normal = normal;
	*hit = 1;
}

static void	try_side_solution(t_vec3 origin, t_vec3 dir, t_cylinder *cylinder,
			t_vec3 axis, double half_height, double t,
			double *best_distance, t_vec3 *best_normal, int *hit)
{
	t_vec3	point;
	double	height_pos;
	t_vec3	normal;

	if (t > EPSILON)
	{
		point = vec3_add(origin, vec3_mul(dir, t));
		height_pos = vec3_dot(vec3_sub(point, cylinder->center), axis);
		if (height_pos >= -half_height && height_pos <= half_height)
		{
			normal = vec3_sub(vec3_sub(point, cylinder->center),
					vec3_mul(axis, height_pos));
			normal = vec3_normalize(normal);
			if (vec3_dot(normal, dir) > 0.0)
				normal = vec3_mul(normal, -1.0);
			update_best(t, normal, best_distance, best_normal, hit);
		}
	}
}

static void	check_side_hits(t_vec3 origin, t_vec3 dir, t_cylinder *cylinder,
			double *best_distance, t_vec3 *best_normal, int *hit)
{
	t_vec3	axis;
	t_vec3	dp;
	double	radius;
	double	half_height;
	double	dir_axis;
	double	dp_axis;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrt_disc;

	axis = vec3_normalize(cylinder->axis);
	dp = vec3_sub(origin, cylinder->center);
	radius = cylinder->diameter * 0.5;
	half_height = cylinder->height * 0.5;
	dir_axis = vec3_dot(dir, axis);
	dp_axis = vec3_dot(dp, axis);
	a = vec3_dot(dir, dir) - dir_axis * dir_axis;
	b = 2.0 * (vec3_dot(dir, dp) - dir_axis * dp_axis);
	c = vec3_dot(dp, dp) - dp_axis * dp_axis - radius * radius;
	if (fabs(a) < EPSILON)
		return ;
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return ;
	sqrt_disc = sqrt(discriminant);
	try_side_solution(origin, dir, cylinder, axis, half_height,
		(-b - sqrt_disc) / (2.0 * a), best_distance, best_normal, hit);
	if (discriminant > EPSILON)
	{
		try_side_solution(origin, dir, cylinder, axis, half_height,
			(-b + sqrt_disc) / (2.0 * a), best_distance, best_normal, hit);
	}
}

static void	check_cap_hit(t_vec3 origin, t_vec3 dir, t_vec3 cap_center,
			t_vec3 cap_normal, double radius, double *best_distance,
			t_vec3 *best_normal, int *hit)
{
	double	denom;
	double	t;
	t_vec3	point;
	t_vec3	diff;

	denom = vec3_dot(dir, cap_normal);
	if (fabs(denom) < EPSILON)
		return ;
	t = vec3_dot(vec3_sub(cap_center, origin), cap_normal) / denom;
	if (t <= EPSILON || t >= *best_distance)
		return ;
	point = vec3_add(origin, vec3_mul(dir, t));
	diff = vec3_sub(point, cap_center);
	if (vec3_dot(diff, diff) > radius * radius + EPSILON)
		return ;
	if (vec3_dot(cap_normal, dir) > 0.0)
		cap_normal = vec3_mul(cap_normal, -1.0);
	update_best(t, cap_normal, best_distance, best_normal, hit);
}

int	intersect_cylinder(t_vec3 origin, t_vec3 dir, t_cylinder *cylinder,
			double *distance, t_vec3 *normal)
{
	t_vec3	axis;
	double	best_distance;
	t_vec3	best_normal;
	int		hit;
	double	radius;
	double	half_height;
	t_vec3	top_center;
	t_vec3	bottom_center;

	if (!cylinder || !distance || !normal)
		return (0);
	axis = vec3_normalize(cylinder->axis);
	best_distance = DBL_MAX;
	hit = 0;
	radius = cylinder->diameter * 0.5;
	half_height = cylinder->height * 0.5;
	check_side_hits(origin, dir, cylinder, &best_distance, &best_normal, &hit);
	top_center = vec3_add(cylinder->center, vec3_mul(axis, half_height));
	bottom_center = vec3_add(cylinder->center, vec3_mul(axis, -half_height));
	check_cap_hit(origin, dir, top_center, axis, radius,
		&best_distance, &best_normal, &hit);
	check_cap_hit(origin, dir, bottom_center, vec3_mul(axis, -1.0), radius,
		&best_distance, &best_normal, &hit);
	if (!hit || best_distance == DBL_MAX)
		return (0);
	*distance = best_distance;
	*normal = best_normal;
	return (1);
}
