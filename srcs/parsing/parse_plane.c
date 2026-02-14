/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:47:17 by stakada           #+#    #+#             */
/*   Updated: 2026/02/14 21:45:27 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*check_plane_values(t_plane plane)
{
	if (!validate_vec3(plane.normal, -1.0, 1.0))
		return (ERR_MSG_ELEM_VALUE);
	if (!validate_colors(plane.color))
		return (ERR_MSG_ELEM_VALUE);
	return (NULL);
}

static char	*validate_and_parse_plane(char **elems, t_plane *plane)
{
	if (count_array(elems) != 3)
		return (ERR_MSG_ELEM_COUNT);
	if (!is_valid_csv(elems[0]) || parse_vec3(elems[0], &(plane->point)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_csv(elems[1]) || parse_vec3(elems[1], &(plane->normal)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_csv(elems[2]) || parse_colors(elems[2], &(plane->color)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	return (NULL);
}

int	parse_plane(char **elems, t_obj **objects, int *read_flags)
{
	char	*err_msg;
	t_plane	*plane;

	plane = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (!plane)
		return (-1);
	err_msg = validate_and_parse_plane(elems, plane);
	if (!err_msg)
		err_msg = check_plane_values(*plane);
	if (err_msg)
	{
		print_error(err_msg, IDENT_PL);
		free(plane);
		return (-1);
	}
	if (register_object(objects, PLANE, (void *)plane) < 0)
	{
		free(plane);
		return (-1);
	}
	*read_flags |= FLAG_PL;
	return (0);
}
