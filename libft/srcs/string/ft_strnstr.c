/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:13:54 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:04:38 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h_index;
	size_t	n_index;

	if (!needle[0])
		return ((char *)haystack);
	h_index = 0;
	while (len > 0 && h_index < len && haystack[h_index])
	{
		n_index = 0;
		while ((h_index + n_index < len) && needle[n_index]
			&& haystack[h_index + n_index] == needle[n_index])
			n_index++;
		if (!needle[n_index])
			return ((char *)&haystack[h_index]);
		h_index++;
	}
	return (0);
}
