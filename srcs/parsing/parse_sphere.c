/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:09:37 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 21:20:43 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*check_sphere_values(t_sphere sphere)
{
	if (!validate_colors(sphere.color))
		return (ERR_MSG_ELEM_VALUE);
	return (NULL);
}

static char	*check_sphere_format(char **elems, t_sphere *sphere)
{
	if (count_array(elems) != 3)
		return (ERR_MSG_ELEM_COUNT);
	if (!is_valid_csv(elems[0]) || parse_vec3(elems[0], &(sphere->center)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_num(elems[1]) || get_double(elems[1],
			&(sphere->diameter)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_csv(elems[2]) || parse_colors(elems[2], &(sphere->color)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	return (NULL);
}

int	parse_sphere(char **elems, t_object **objects, int *read_flags)
{
	char		*err_msg;
	t_sphere	*sphere;

	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (!sphere)
		return (-1);
	err_msg = check_sphere_format(elems, sphere);
	if (!err_msg)
		err_msg = check_sphere_values(*sphere);
	if (!validate_elements(err_msg, IDENT_SP))
	{
		free(sphere);
		return (-1);
	}
	if (register_object(objects, SPHERE, (void *)sphere) < 0)
	{
		free(sphere);
		return (-1);
	}
	*read_flags |= FLAG_SP;
	return (0);
}
