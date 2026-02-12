/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:51:09 by stakada           #+#    #+#             */
/*   Updated: 2026/02/12 16:55:55 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	is_valid_num_len(const char *str, size_t len)
{
	size_t	i;
	int		dot_count;
	int		digit_count;

	if (!str || !*str || len == 0)
		return (INVALID);
	dot_count = 0;
	digit_count = 0;
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (i < len)
	{
		if (str[i] == '.')
			dot_count++;
		else if (ft_isdigit(str[i]))
			digit_count++;
		else
			return (INVALID);
		i++;
	}
	if (dot_count > 1 || digit_count == 0)
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
