/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:38:26 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:08:07 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *)s1)[index] != ((unsigned char *)s2)[index])
			return (((unsigned char *)s1)[index]
				- ((unsigned char *)s2)[index]);
		index++;
	}
	return (0);
}
