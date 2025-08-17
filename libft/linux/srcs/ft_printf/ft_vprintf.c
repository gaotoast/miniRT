/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:16:22 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:11:16 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_switch(const char *format, va_list ap, int fd)
{
	if (*format == '%')
		return (ft_fputc('%', fd));
	else if (*format == 'c')
		return (ft_fputc(va_arg(ap, int), fd));
	else if (*format == 's')
		return (ft_fputs(va_arg(ap, char *), fd));
	else if (*format == 'u')
		return (ft_fputu(va_arg(ap, unsigned int), fd));
	else if (*format == 'd' || *format == 'i')
		return (ft_fputi(va_arg(ap, int), fd));
	else if (*format == 'x' || *format == 'X')
		return (ft_fputx(va_arg(ap, unsigned int), fd, *format));
	else if (*format == 'p')
		return (ft_fputp(va_arg(ap, unsigned long long), fd));
	else
		return (-1);
}

int	ft_vprintf(const char *format, va_list ap)
{
	int	ret;
	int	w_ret;

	ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			w_ret = ft_printf_switch(format, ap, STDOUT_FILENO);
			if (w_ret < 0)
				return (-1);
			ret += w_ret;
		}
		else
		{
			w_ret = ft_fputc(*format, STDOUT_FILENO);
			if (w_ret < 0)
				return (-1);
			ret += w_ret;
		}
		format++;
	}
	return (ret);
}
