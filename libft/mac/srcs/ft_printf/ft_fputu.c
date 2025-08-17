/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 06:50:03 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:10:08 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fputu(unsigned int unum, int fd)
{
	int	ret;
	int	wret;

	ret = 0;
	wret = ft_uitoa_base(unum, BASE_10, fd);
	if (wret < 0)
		return (-1);
	ret += wret;
	return (ret);
}
