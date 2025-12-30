/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:13:12 by stakada           #+#    #+#             */
/*   Updated: 2025/12/30 16:46:17 by kinamura         ###   ########.fr       */
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
	if (endptr && !(*endptr == '\0' || *endptr == '\n'))
		return (-1);
	return (0);
}

static int	parse_tokens_and_assign(char *str, double *a, double *b, double *c)
{
	char	*comma1;
	char	*comma2;

	if (!str)
		return (-1);
	comma1 = str;
	while (*comma1 && *comma1 != ',')
		comma1++;
	if (*comma1 != ',')
		return (-1);
	*comma1 = '\0';
	comma2 = comma1 + 1;
	while (*comma2 && *comma2 != ',')
		comma2++;
	if (*comma2 != ',')
		return (-1);
	*comma2 = '\0';
	if (get_double(str, a) < 0 || get_double(comma1 + 1, b) < 0
		|| get_double(comma2 + 1, c) < 0)
		return (-1);
	return (0);
}

int	parse_colors(char *str, t_color *color)
{
	double	red;
	double	green;
	double	blue;
	int		ret;

	if (!str || !color)
		return (-1);
	red = (double)color->red;
	green = (double)color->green;
	blue = (double)color->blue;
	ret = parse_tokens_and_assign(str, &red, &green, &blue);
	color->red = (int)red;
	color->green = (int)green;
	color->blue = (int)blue;
	return ret;
}

int	parse_vec3(char *str, t_vec3 *vec)
{
	if (!str || !vec)
		return (-1);
	return (parse_tokens_and_assign(str, &(vec->x), &(vec->y), &(vec->z)));
}
