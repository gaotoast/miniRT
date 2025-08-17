/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:10:19 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 16:13:19 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (n < size)
		size = n;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, size);
	str[size] = '\0';
	return (str);
}
