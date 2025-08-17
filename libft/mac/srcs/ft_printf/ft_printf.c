/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:29:33 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:10:15 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	ssize_t	ret;

	ret = 0;
	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	if (ret < 0)
		return (-1);
	return (ret);
}
