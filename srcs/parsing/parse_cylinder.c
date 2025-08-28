/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:53:26 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 22:24:30 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*check_cylinder_values(t_cylinder cylinder)
{
	if (cylinder.diameter <= 0.0)
		return (ERR_MSG_ELEM_VALUE);
	if (cylinder.height <= 0.0)
		return (ERR_MSG_ELEM_VALUE);
	if (!validate_colors(cylinder.color))
		return (ERR_MSG_ELEM_VALUE);
	return (NULL);
}

static char	*check_cylinder_format(char **elems, t_cylinder *cylinder)
{
	if (count_array(elems) != 5)
		return (ERR_MSG_ELEM_COUNT);
	if (!is_valid_csv(elems[0]) || parse_vec3(elems[0],
			&(cylinder->center)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_csv(elems[1]) || parse_vec3(elems[1], &(cylinder->axis)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_num(elems[2]) || get_double(elems[2],
			&(cylinder->diameter)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_num(elems[3]) || get_double(elems[3],
			&(cylinder->height)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_csv(elems[4]) || parse_colors(elems[4],
			&(cylinder->color)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	return (NULL);
}

int	parse_cylinder(char **elems, t_object **objects, int *read_flags)
{
	char		*err_msg;
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	if (!cylinder)
		return (-1);
	err_msg = check_cylinder_format(elems, cylinder);
	if (!err_msg)
		err_msg = check_cylinder_values(*cylinder);
	if (err_msg)
	{
		print_error(err_msg, IDENT_CY);
		free(cylinder);
		return (-1);
	}
	if (register_object(objects, CYLINDER, (void *)cylinder) < 0)
	{
		free(cylinder);
		return (-1);
	}
	*read_flags |= FLAG_CY;
	return (0);
}
