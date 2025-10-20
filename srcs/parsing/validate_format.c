/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:51:09 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 21:23:55 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_num(const char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (INVALID);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '0')
	{
		i++;
		if (str[i] != '\0' && str[i] != '.' && str[i] != '\n' && str[i] != ',')
			return (INVALID);
	}
	return (VALID);
}

int	is_valid_csv(const char *str)
{
	int		comma_cnt;
	char	*temp;
	char	*next;

	if (!str)
		return (INVALID);
	temp = (char *)str;
	comma_cnt = 0;
	while (*temp)
	{
		if (!is_valid_num(temp))
			return (INVALID);
		next = ft_strchr(temp, ',');
		if (!next)
			break ;
		temp = next + 1;
		comma_cnt++;
	}
	if (comma_cnt != 2)
		return (INVALID);
	return (VALID);
}
