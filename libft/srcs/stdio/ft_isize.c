/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:23:26 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:07:28 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_isize(int n, int base)
{
	long long	ln;
	size_t		ret;

	ln = n;
	if (n == 0)
		return (1);
	ret = 0;
	if (ln < 0)
	{
		ln = -ln;
		ret++;
	}
	while (ln != 0)
	{
		ret++;
		ln /= base;
	}
	return (ret);
}
