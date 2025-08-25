/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:36:21 by stakada           #+#    #+#             */
/*   Updated: 2025/08/24 16:23:31 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	is_valid_extension(const char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 3, EXT, 3) == 0)
		return (1);
	return (0);
}

int	is_accessible_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

int	check_args(int argc, char **argv)
{
	char	*filename;

	if (argc != 2)
	{
		print_error(ERR_MSG_USAGE, PROGRAM);
		return (-1);
	}
	filename = argv[1];
	if (!is_valid_extension(filename))
	{
		print_error(ERR_MSG_EXT, EXT);
		return (-1);
	}
	if (!is_accessible_file(filename))
	{
		print_error(ERR_MSG_FILE);
		return (-1);
	}
	return (0);
}
