/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:29:46 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 17:04:41 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*check_camera_values(t_camera camera)
{
	if (!validate_vec3(camera.direction, 0.0, 1.0))
		return (ERR_MSG_NORM_VEC);
	if (!validate_double(camera.fov, 0.0, 180.0))
		return (ERR_MSG_RANGE);
	return (NULL);
}

static char	*check_camera_format(char **elems, t_camera *camera, int read_flags)
{
	if (read_flags & FLAG_C)
		return (ERR_MSG_DUP_IDENT);
	if (count_array(elems) != 3)
		return (ERR_MSG_ELEM_COUNT);
	if (parse_vec3(elems[0], &(camera->position)) < 0)
		return (ERR_MSG_VEC_FORMAT);
	if (parse_vec3(elems[1], &(camera->direction)) < 0)
		return (ERR_MSG_VEC_FORMAT);
	if (get_double(elems[2], &(camera->fov)) < 0)
		return (ERR_MSG_RANGE);
	return (NULL);
}

int	parse_camera(char **elems, t_camera *camera, int *read_flags)
{
	char	*err_msg;

	err_msg = check_camera_format(elems, camera, *read_flags);
	if (!err_msg)
		err_msg = check_camera_values(*camera);
	if (!validate_elements(err_msg, IDENT_C))
		return (-1);
	*read_flags |= FLAG_C;
	return (0);
}
