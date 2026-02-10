/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:28:28 by stakada           #+#    #+#             */
/*   Updated: 2026/02/09 16:55:16 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec3	vec3_rotate(t_vec3 v, t_vec3 axis, double angle_deg)
{
	double	angle_rad;
	double	cos_a;
	double	sin_a;
	t_vec3	k;
	t_vec3	result;

	angle_rad = angle_deg * PI / 180.0;
	cos_a = cos(angle_rad);
	sin_a = sin(angle_rad);
	k = vec3_normalize(axis);
	result = vec3_mul(v, cos_a);
	result = vec3_add(result, vec3_mul(vec3_cross(k, v), sin_a));
	result = vec3_add(result, vec3_mul(k, vec3_dot(k, v) * (1.0 - cos_a)));
	return (result);
}
