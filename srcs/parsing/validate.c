/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:29:06 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 17:51:21 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	validate_scene(int read_flags)
{
	int	required;

	required = FLAG_A | FLAG_C | FLAG_L;
	if ((read_flags & required) != required)
	{
		if (!(read_flags & FLAG_A))
			print_error(ERR_MSG_MISSING_AMBIENT);
		if (!(read_flags & FLAG_C))
			print_error(ERR_MSG_MISSING_CAMERA);
		if (!(read_flags & FLAG_L))
			print_error(ERR_MSG_MISSING_LIGHT);
		return (INVALID);
	}
	if (!(read_flags & (FLAG_SP | FLAG_PL | FLAG_CY)))
	{
		print_error(ERR_MSG_NO_OBJECTS);
		return (INVALID);
	}
	return (VALID);
}

int	validate_elements(char *err_msg, char *identifier)
{
	if (err_msg)
	{
		print_error(err_msg, identifier);
		return (INVALID);
	}
	return (VALID);
}

int	validate_double(double n, double min, double max)
{
	if (n < min || n > max)
		return (INVALID);
	return (VALID);
}

int	validate_colors(t_color color)
{
	if (!(color.r >= 0 && color.r <= 255))
		return (INVALID);
	if (!(color.g >= 0 && color.g <= 255))
		return (INVALID);
	if (!(color.b >= 0 && color.b <= 255))
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
