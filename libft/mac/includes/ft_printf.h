/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:25:40 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:09:49 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BASE_10 "0123456789"
# define BASE_LOW_16 "0123456789abcdef"
# define BASE_TOP_16 "0123456789ABCDEF"

int		ft_fputi(int num, int fd);
int		ft_fputp(unsigned long long unum, int fd);
int		ft_fputs(const char *s, int fd);
int		ft_fputc(int c, int fd);
int		ft_fputu(unsigned int unum, int fd);
int		ft_fputx(unsigned int unum, int fd, int c);
int		ft_printf_switch(const char *format, va_list *ap, int fd);
int		ft_vdprintf(int fd, const char *format, va_list ap);
int		ft_vprintf(const char *format, va_list ap);
int		ft_uitoa_base(unsigned int num, char *base, int fd);
int		ft_ulltoa_base(unsigned long long num, char *base, int fd);
int		ft_dprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif