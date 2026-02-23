/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:03:20 by stakada           #+#    #+#             */
/*   Updated: 2026/02/15 02:37:41 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	validate_double_inclusive(double n, double min, double max)
{
	if (n < min || n > max)
		return (INVALID);
	return (VALID);
}

int	validate_double_exclusive(double n, double min, double max)
{
	if (n <= min || n >= max)
		return (INVALID);
	return (VALID);
}

int	validate_colors(t_rgb color)
{
	if (color.red < 0 || color.red > 255)
		return (INVALID);
	if (color.green < 0 || color.green > 255)
		return (INVALID);
	if (color.blue < 0 || color.blue > 255)
		return (INVALID);
	return (VALID);
}

int	validate_normalized_vec3(t_vec3 vec)
{
	double	len_squared;

	len_squared = vec3_dot(vec, vec);
	if (fabs(len_squared - 1.0) > NORM_EPSILON)
		return (INVALID);
	return (VALID);
}
