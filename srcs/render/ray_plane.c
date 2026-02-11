/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:18 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/11 20:57:15 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	calculate_plane_hit(t_ray ray, t_plane *pl, t_hit *hit)
{
	double	denom;
	double	t;

	if (!pl || !hit)
		return (0);
	denom = vec3_dot(ray.direction, pl->normal);
	if (fabs(denom) < EPSILON)
		return (0);
	t = vec3_dot(vec3_sub(pl->point, ray.origin), pl->normal) / denom;
	if (t <= EPSILON)
		return (0);
	hit->distance = t;
	if (denom > 0.0)
		hit->normal = vec3_mul(pl->normal, -1.0);
	else
		hit->normal = pl->normal;
	return (1);
}
