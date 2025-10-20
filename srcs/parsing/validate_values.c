/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 21:03:20 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 21:27:05 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	validate_double(double n, double min, double max)
{
	if (n < min || n > max)
		return (INVALID);
	return (VALID);
}

int	validate_colors(t_color color)
{
	if (color.r < 0 || color.r > 255)
		return (INVALID);
	if (color.g < 0 || color.g > 255)
		return (INVALID);
	if (color.b < 0 || color.b > 255)
		return (INVALID);
	return (VALID);
}

int	validate_vec3(t_vec3 vec, double min, double max)
{
	if (vec.x < min || vec.x > max)
		return (INVALID);
	if (vec.y < min || vec.y > max)
		return (INVALID);
	if (vec.z < min || vec.z > max)
		return (INVALID);
	return (VALID);
}
