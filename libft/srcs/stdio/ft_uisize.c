/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uisize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:26:14 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:07:43 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uisize(unsigned int n, int base)
{
	size_t	size;

	if (n == 0)
		return (1);
	size = 0;
	while (n != 0)
	{
		size++;
		n /= (unsigned int)base;
	}
	return (size);
}
