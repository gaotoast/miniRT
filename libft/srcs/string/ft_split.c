/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:39:24 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 16:11:45 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	contents_free(char **result, size_t count)
{
	while (count > 0)
	{
		count--;
		free(result[count]);
	}
	free(result);
}

static int	count_words(char const *str, char c)
{
	int		count;
	int		flag;
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	count = 0;
	flag = 0;
	while (str[index])
	{
		if (str[index] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (str[index] == c)
			flag = 0;
		index++;
	}
	return (count);
}

static char	**ft_separate(const char *s, char c, char **result, size_t *count)
{
	size_t	index;
	size_t	start;

	index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		start = index;
		while (s[index] && s[index] != c)
			index++;
		if (index > start)
		{
			result[*count] = ft_strndup(s + start, index - start);
			if (!result[*count])
			{
				contents_free(result, *count);
				return (NULL);
			}
			(*count)++;
		}
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**result;
	size_t	count;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	count = 0;
	if (!ft_separate(s, c, result, &count))
		return (NULL);
	result[count] = NULL;
	return (result);
}
