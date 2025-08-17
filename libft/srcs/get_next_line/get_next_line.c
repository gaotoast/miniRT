/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 06:34:01 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:08:44 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_stradd(char **s1, const char *s2)
{
	char	*tmp;

	if (!s2)
		return ;
	if (!*s1)
	{
		*s1 = ft_strdup(s2);
		return ;
	}
	tmp = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = tmp;
}

char	*ft_get_line(char *str)
{
	size_t	index;
	size_t	n_flag;
	char	*buf;

	index = 0;
	if (!str[index])
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	n_flag = (str[index] == '\n');
	buf = (char *)malloc(sizeof(char) * (index + n_flag + 1));
	if (!buf)
		return (NULL);
	ft_memcpy(buf, str, index + n_flag);
	buf[index + n_flag] = '\0';
	return (buf);
}

char	*ft_next_str(char *str)
{
	size_t	index;
	char	*buf;

	index = 0;
	while (str[index] && str[index] != '\n')
		index++;
	if (!str[index])
	{
		free(str);
		return (NULL);
	}
	buf = (char *)malloc(sizeof(char) * (ft_strlen(str) - index));
	if (!buf)
	{
		free(str);
		return (NULL);
	}
	index++;
	ft_memcpy(buf, &str[index], (ft_strlen(str) - index));
	buf[ft_strlen(str) - index] = '\0';
	free(str);
	return (buf);
}

char	*ft_read_file(int fd, char *str)
{
	char	*buf;
	ssize_t	size;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	size = 1;
	while (size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[size] = '\0';
		ft_stradd(&str, buf);
		if (!str || ft_strchr(str, '\n'))
			break ;
	}
	free(buf);
	return (str);
}

size_t	get_next_line(int fd, char **line)
{
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (0);
	str = ft_read_file(fd, str);
	if (!str)
		return (0);
	*line = ft_get_line(str);
	str = ft_next_str(str);
	if (!*line)
		return (0);
	return (ft_strlen(*line));
}
