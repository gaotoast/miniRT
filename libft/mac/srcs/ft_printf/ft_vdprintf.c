/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:32 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:10:24 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	int	ret;
	int	wret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			wret = ft_printf_switch(format, &ap, fd);
			if (wret < 0)
				return (-1);
			ret += wret;
		}
		else
		{
			wret = ft_fputc(*format, fd);
			if (wret < 0)
				return (-1);
			ret += wret;
		}
		format++;
	}
	return (ret);
}
