/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:31:55 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:08:14 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (dst == src)
		return (dst);
	if (dst > src)
	{
		index = len;
		while (index > 0)
		{
			index--;
			((char *)dst)[index] = ((char *)src)[index];
		}
	}
	else
	{
		index = 0;
		while (index < len)
		{
			((char *)dst)[index] = ((char *)src)[index];
			index++;
		}
	}
	return (dst);
}
