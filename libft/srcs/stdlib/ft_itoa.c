/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:40:26 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:05:45 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(long n)
{
	size_t	size;

	size = 1;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 9)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	ln;
	char		*str;
	size_t		size;

	ln = n;
	size = ft_size(n);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (ln < 0)
	{
		ln *= -1;
		str[0] = '-';
	}
	if (ln == 0)
		str[0] = '0';
	while (ln > 0)
	{
		str[size--] = (ln % 10) + '0';
		ln /= 10;
	}
	return (str);
}
