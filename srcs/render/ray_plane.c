/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:18 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/11 22:30:07 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	find_plane_hit_t(t_ray ray, t_vec3 point, t_vec3 normal)
{
	double	denom;
	double	t;

	denom = vec3_dot(ray.direction, normal);
	if (fabs(denom) < EPSILON)
		return (-1.0);
	t = vec3_dot(vec3_sub(point, ray.origin), normal) / denom;
	if (t <= EPSILON)
		return (-1.0);
	return (t);
}

int	calculate_plane_hit(t_ray ray, t_plane *pl, t_hit *hit)
{
	double	t;

	if (!pl || !hit)
		return (0);
	t = find_plane_hit_t(ray, pl->point, pl->normal);
	if (t <= EPSILON)
		return (0);
	hit->distance = t;
	hit->normal = front_normal(pl->normal, ray.direction);
	return (1);
}
