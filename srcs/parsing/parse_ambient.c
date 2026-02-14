/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:02:48 by stakada           #+#    #+#             */
/*   Updated: 2026/02/14 21:44:29 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*check_ambient_values(t_ambient ambient)
{
	if (!validate_double(ambient.ratio, 0.0, 1.0))
		return (ERR_MSG_ELEM_VALUE);
	if (!validate_colors(ambient.color))
		return (ERR_MSG_ELEM_VALUE);
	return (NULL);
}

static char	*validate_and_parse_ambient(char **elems, t_ambient *ambient,
		int read_flags)
{
	if (read_flags & FLAG_A)
		return (ERR_MSG_DUP_IDENT);
	if (count_array(elems) != 2)
		return (ERR_MSG_ELEM_COUNT);
	if (!is_valid_num(elems[0]) || get_double(elems[0], &(ambient->ratio),
			NULL) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	if (!is_valid_csv(elems[1]) || parse_colors(elems[1],
			&(ambient->color)) < 0)
		return (ERR_MSG_ELEM_FORMAT);
	return (NULL);
}

int	parse_ambient(char **elems, t_ambient *ambient, int *read_flags)
{
	char	*err_msg;

	err_msg = validate_and_parse_ambient(elems, ambient, *read_flags);
	if (!err_msg)
		err_msg = check_ambient_values(*ambient);
	if (err_msg)
	{
		print_error(err_msg, IDENT_A);
		return (-1);
	}
	*read_flags |= FLAG_A;
	return (0);
}
