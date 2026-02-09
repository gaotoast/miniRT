/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:13:12 by stakada           #+#    #+#             */
/*   Updated: 2026/02/09 18:07:09 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	get_int(char *str, int *n)
{
	char	*endptr;
	long	ret;

	if (!str || !*str || !n)
		return (-1);
	endptr = NULL;
	ret = ft_strtol(str, &endptr, 10);
	if (endptr && !(*endptr == '\0' || *endptr == '\n'))
		return (-1);
	if (ret < (long)INT_MIN || ret > (long)INT_MAX)
		return (-1);
	*n = (int)ret;
	return (0);
}

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

static int	split_and_get_tokens(char *str, char **token1, char **token2,
		char **token3)
{
	char	*comma1;
	char	*comma2;

	if (!str)
		return (-1);
	comma1 = ft_strchr(str, ',');
	if (!comma1)
		return (-1);
	*comma1 = '\0';
	comma2 = ft_strchr(comma1 + 1, ',');
	if (!comma2)
		return (-1);
	*comma2 = '\0';
	*token1 = str;
	*token2 = comma1 + 1;
	*token3 = comma2 + 1;
	return (0);
}

int	parse_colors(char *str, t_color *color)
{
	char	*r_str;
	char	*g_str;
	char	*b_str;

	if (!str || !color)
		return (-1);
	if (split_and_get_tokens(str, &r_str, &g_str, &b_str) < 0)
		return (-1);
	if (get_int(r_str, &color->red) < 0 || get_int(g_str, &color->green) < 0
		|| get_int(b_str, &color->blue) < 0)
		return (-1);
	return (0);
}

int	parse_vec3(char *str, t_vec3 *vec)
{
	char	*x_str;
	char	*y_str;
	char	*z_str;

	if (!str || !vec)
		return (-1);
	if (split_and_get_tokens(str, &x_str, &y_str, &z_str) < 0)
		return (-1);
	if (get_double(x_str, &vec->x) < 0 || get_double(y_str, &vec->y) < 0
		|| get_double(z_str, &vec->z) < 0)
		return (-1);
	return (0);
}
