/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:13:12 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 20:41:50 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	get_int(const char *str, int *num, char **endptr)
{
	long long	ret;

	ret = ft_strtol(str, endptr, 10);
	if (endptr && *endptr && *endptr == str)
		return (-1);
	if (ret < (long long)INT_MIN || ret > (long long)INT_MAX)
		return (-1);
	*num = (int)ret;
	return (0);
}

int	get_double(const char *str, double *num, char **endptr)
{
	*num = ft_strtod(str, endptr);
	if (endptr && *endptr && *endptr == str)
		return (-1);
	return (0);
}

int	parse_colors(char *str, t_color *color)
{
	char	*p;

	if (!str || !color)
		return (-1);
	p = str;
	if (get_int(p, &color->red, &p) < 0 || !*p || *p++ != ',')
		return (-1);
	if (get_int(p, &color->green, &p) < 0 || !*p || *p++ != ',')
		return (-1);
	if (get_int(p, &color->blue, &p) < 0 || *p)
		return (-1);
	return (0);
}

int	parse_vec3(char *str, t_vec3 *vec)
{
	char	*p;

	if (!str || !vec)
		return (-1);
	p = str;
	if (get_double(p, &vec->x, &p) < 0 || !*p || *p++ != ',')
		return (-1);
	if (get_double(p, &vec->y, &p) < 0 || !*p || *p++ != ',')
		return (-1);
	if (get_double(p, &vec->z, &p) < 0 || *p)
		return (-1);
	return (0);
}
