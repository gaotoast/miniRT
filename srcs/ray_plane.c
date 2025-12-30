/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:18 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/30 14:35:40 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersect_plane(t_vec3 origin, t_vec3 dir, t_plane *plane,
			double *distance, t_vec3 *normal)
{
	t_vec3	n;
	double	denom;
	double	t;

	if (!plane || !distance || !normal)
		return (0);
	/* 平面の法線と通過点を用いてレイと平面の交差を求める */
	n = vec3_normalize(plane->normal);
	denom = vec3_dot(dir, n);
	if (fabs(denom) < EPSILON)
		return (0);
	t = vec3_dot(vec3_sub(plane->point, origin), n) / denom;
	if (t <= EPSILON)
		return (0);
	*distance = t;
	if (denom > 0.0)
		*normal = vec3_mul(n, -1.0);
	else
		*normal = n;
	return (1);
}
