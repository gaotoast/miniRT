/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:06:17 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 17:42:44 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*check_light_values(t_light light)
{
	if (!validate_double(light.brightness, 0.0, 1.0))
		return (ERR_MSG_ELEM_VALUE);
	if (!validate_colors(light.color))
		return (ERR_MSG_ELEM_VALUE);
	return (NULL);
}

static char	*check_light_format(char **elems, t_light *light, int read_flags)
{
	if (read_flags & FLAG_L)
		return (ERR_MSG_DUP_IDENT);
	if (count_array(elems) != 3)
		return (ERR_MSG_ELEM_COUNT);
	if (parse_vec3(elems[0], &(light->position)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (get_double(elems[1], &(light->brightness)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (parse_colors(elems[2], &(light->color)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	return (NULL);
}

int	parse_light(char **elems, t_light *light, int *read_flags)
{
	char	*err_msg;

	err_msg = check_light_format(elems, light, *read_flags);
	if (!err_msg)
		err_msg = check_light_values(*light);
	if (!validate_elements(err_msg, IDENT_L))
		return (-1);
	*read_flags |= FLAG_L;
	return (0);
}
