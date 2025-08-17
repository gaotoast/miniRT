/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:42:58 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:04:23 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	s_index;
	size_t	d_index;
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	if (!dst && dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	d_index = d_len;
	if (dstsize <= d_len)
		return (dstsize + s_len);
	s_index = 0;
	while (src[s_index] && d_index + 1 < dstsize)
	{
		dst[d_index] = src[s_index];
		s_index++;
		d_index++;
	}
	dst[d_index] = '\0';
	return (d_len + s_len);
}
