/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:35:13 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:10:21 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ulltoa_base(unsigned long long num, char *base, int fd)
{
	int		ret;
	int		wret;
	int		base_len;
	char	n;

	ret = 0;
	base_len = ft_strlen(base);
	if (num >= (unsigned long long)base_len)
	{
		wret = ft_uitoa_base(num / base_len, base, fd);
		if (wret < 0)
			return (-1);
		ret += wret;
	}
	n = base[num % base_len];
	wret = (ft_fputc(n, fd));
	if (wret < 0)
		return (-1);
	ret += wret;
	return (ret);
}
