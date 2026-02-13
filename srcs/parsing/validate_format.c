/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:51:09 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 20:52:48 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_char(char c, int *has_dot, int *before_dot, int *after_dot)
{
	if (c == '.')
	{
		if (*has_dot || !*before_dot)
			return (INVALID);
		*has_dot = 1;
	}
	else if (ft_isdigit(c))
	{
		if (!*has_dot)
			*before_dot = 1;
		else
			*after_dot = 1;
	}
	else
		return (INVALID);
	return (VALID);
}

static int	is_valid_num_len(const char *str, size_t len)
{
	size_t	i;
	int		has_dot;
	int		before_dot;
	int		after_dot;

	if (!str || !*str || len == 0)
		return (INVALID);
	has_dot = 0;
	before_dot = 0;
	after_dot = 0;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < len)
	{
		if (!check_char(str[i], &has_dot, &before_dot, &after_dot))
			return (INVALID);
		i++;
	}
	if (!before_dot || (has_dot && !after_dot))
		return (INVALID);
	return (VALID);
}

int	is_valid_num(const char *str)
{
	if (!str || !*str)
		return (INVALID);
	return (is_valid_num_len(str, ft_strlen(str)));
}

int	is_valid_csv(const char *str)
{
	const char	*start;
	const char	*end;
	int			num_cnt;

	if (!str || !*str)
		return (INVALID);
	start = str;
	num_cnt = 0;
	while (num_cnt < 3 && *start)
	{
		end = start;
		while (*end && *end != ',')
			end++;
		if (!is_valid_num_len(start, end - start))
			return (INVALID);
		num_cnt++;
		if (!*end)
			break ;
		start = end + 1;
	}
	if (num_cnt == 3 && !*end)
		return (VALID);
	return (INVALID);
}
