/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mktemp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:06:26 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:05:52 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_suffix(char *suffix)
{
	size_t				len;
	size_t				i;
	unsigned int		r;

	len = ft_strlen(suffix);
	i = 0;
	while (i < len)
	{
		r = ft_random();
		r = r % 62;
		if (r < 10)
			suffix[i] = '0' + r;
		else if (r < 36)
			suffix[i] = 'a' + (r - 10);
		else
			suffix[i] = 'A' + (r - 36);
		i++;
	}
}

char	*ft_mktemp(char *template)
{
	size_t	len;
	char	*suffix;

	len = ft_strlen(template);
	suffix = &template[len - ft_strlen(SUFFIX_TEMP)];
	if (!ft_strncmp(suffix, SUFFIX_TEMP, ft_strlen(SUFFIX_TEMP)))
	{
		while (1)
		{
			set_suffix(suffix);
			if (access(template, F_OK))
				break ;
		}
	}
	else
		return (NULL);
	return (template);
}
