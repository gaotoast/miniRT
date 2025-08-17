/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:10:51 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:05:58 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft__space_sign(char **str)
{
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-')
	{
		(*str)++;
		return (-1);
	}
	else if (**str == '+')
		(*str)++;
	return (1);
}

void	ft__base_check(char **ptr, int *base)
{
	if (*base == 0)
	{
		if (**ptr == '0')
		{
			if (*(*ptr + 1) == 'x' || *(*ptr + 1) == 'X')
			{
				*base = 16;
				*ptr += 2;
			}
			else
				*base = 8;
		}
		else
			*base = 10;
	}
	else if (*base == 16 && **ptr == '0'
		&& (*(*ptr + 1) == 'x' || *(*ptr + 1) == 'X'))
		*ptr += 2;
}

long	ft_strtol(const char *str, char **endptr, int base)
{
	char	*p;
	int		sign;
	long	ret;
	int		digit;

	p = (char *)str;
	sign = ft__space_sign(&p);
	ft__base_check(&p, &base);
	ret = 0;
	while ((base == 16 && ft_ishexdigit(*p)) || (base != 16 && ft_isdigit(*p)))
	{
		if (base == 16)
			digit = ft_hextoi(*p);
		else
			digit = (*p - '0');
		if (sign == 1 && ((LONG_MAX - digit) / base < ret))
			return (LONG_MAX);
		else if (sign == -1 && ((LONG_MIN + digit) / base > -ret))
			return (LONG_MIN);
		ret = ret * base + digit;
		p++;
	}
	if (endptr != NULL)
		*endptr = p;
	return (sign * ret);
}
