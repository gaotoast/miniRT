/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:35:18 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:10:18 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uitoa_base(unsigned int num, char *base, int fd)
{
	int		ret;
	int		wret;
	int		base_len;
	char	n;

	ret = 0;
	base_len = ft_strlen(base);
	if (num >= (unsigned int)base_len)
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
