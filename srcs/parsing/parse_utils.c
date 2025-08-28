/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:13:12 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 17:04:19 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_double(char *str, double *n)
{
	char	*endptr;

	if (!str || !*str || !n)
		return (-1);
	endptr = NULL;
	*n = ft_strtod(str, &endptr);
	if (endptr && *endptr != '\0')
	{
		print_error(ERR_MSG_NUM_FORMAT, str);
		return (-1);
	}
	return (0);
}

int	parse_colors(char *str, t_color *color)
{
	char	**tokens;

	tokens = ft_split(str, ',');
	if (!tokens)
		return (-1);
	if (get_double(tokens[0], &(color->r)) < 0 || get_double(tokens[1],
			&(color->g)) < 0 || get_double(tokens[2], &(color->b)) < 0)
	{
		free_2d_array(tokens);
		return (-1);
	}
	free_2d_array(tokens);
	return (0);
}

int	parse_vec3(char *str, t_vec3 *vec)
{
	char	**tokens;
	int		count;

	if (!str || !vec)
		return (-1);
	tokens = ft_split(str, ',');
	if (!tokens)
	{
		return (-1);
	}
	count = count_array(tokens);
	if (count != 3)
	{
		print_error(ERR_MSG_VEC_FORMAT, str);
		free_2d_array(tokens);
		return (-1);
	}
	if (get_double(tokens[0], &(vec->x)) < 0 || get_double(tokens[1],
			&(vec->y)) < 0 || get_double(tokens[2], &(vec->z)) < 0)
	{
		free_2d_array(tokens);
		return (-1);
	}
	free_2d_array(tokens);
	return (0);
}
