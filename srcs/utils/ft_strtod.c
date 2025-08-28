/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 12:49:25 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 20:47:03 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	get_integer_part(const char **s)
{
	int		i;
	double	result;

	i = 0;
	result = 0.0;
	while ((*s)[i] && ft_isdigit((*s)[i]))
	{
		result = result * 10.0 + ((*s)[i] - '0');
		i++;
	}
	*s += i;
	return (result);
}

static double	get_fractional_part(const char **s)
{
	int		i;
	double	result;
	double	power;

	i = 0;
	result = 0.0;
	power = 1.0;
	while ((*s)[i] && ft_isdigit((*s)[i]))
	{
		power = power * 10.0;
		result = result + ((*s)[i] - '0') / power;
		i++;
	}
	*s += i;
	return (result);
}

static int	is_valid_number_start(const char *s)
{
	if (*s == '+' || *s == '-')
		return (0);
	if (*s == '.' && !ft_isdigit(*(s + 1)))
		return (0);
	if (!ft_isdigit(*s) && *s != '.')
		return (0);
	return (1);
}

static int	check_valid_format(const char **nptr, double *sign)
{
	const char	*start;

	start = *nptr;
	*sign = 1.0;
	while (**nptr && ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			*sign = -(*sign);
		(*nptr)++;
	}
	if (!is_valid_number_start(*nptr))
	{
		*nptr = start;
		return (0);
	}
	return (1);
}

double	ft_strtod(const char *nptr, char **endptr)
{
	const char	*start;
	double		sign;
	double		result;
	double		fractional;

	start = nptr;
	if (!check_valid_format(&nptr, &sign))
	{
		if (endptr)
			*endptr = (char *)start;
		return (0.0);
	}
	result = get_integer_part(&nptr);
	if (*nptr == '.')
	{
		nptr++;
		fractional = get_fractional_part(&nptr);
		result = result + fractional;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (sign * result);
}
