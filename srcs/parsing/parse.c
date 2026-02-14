/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:04:24 by stakada           #+#    #+#             */
/*   Updated: 2026/02/12 17:09:50 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	dispatch_parse(char **tokens, t_scene *scene, int *read_flags)
{
	char	*ident;

	ident = tokens[0];
	if (ft_strcmp(ident, IDENT_A) == 0)
		return (parse_ambient(tokens + 1, &scene->ambient, read_flags));
	else if (ft_strcmp(ident, IDENT_C) == 0)
		return (parse_camera(tokens + 1, &scene->camera, read_flags));
	else if (ft_strcmp(ident, IDENT_L) == 0)
		return (parse_light(tokens + 1, &scene->light, read_flags));
	else if (ft_strcmp(ident, IDENT_SP) == 0)
		return (parse_sphere(tokens + 1, &scene->objects, read_flags));
	else if (ft_strcmp(ident, IDENT_PL) == 0)
		return (parse_plane(tokens + 1, &scene->objects, read_flags));
	else if (ft_strcmp(ident, IDENT_CY) == 0)
		return (parse_cylinder(tokens + 1, &scene->objects, read_flags));
	else
	{
		print_error(ERR_MSG_IDENT, ident);
		return (-1);
	}
}

static int	parse_line(char *line, t_scene *scene, int *read_flags)
{
	char	**tokens;
	size_t	len;

	if (!line || !scene || !read_flags)
		return (-1);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (-1);
	if (!tokens[0])
	{
		ft_free_array2((void **)tokens);
		print_error(ERR_MSG_LINE);
		return (-1);
	}
	if (dispatch_parse(tokens, scene, read_flags) < 0)
	{
		ft_free_array2((void **)tokens);
		return (-1);
	}
	ft_free_array2((void **)tokens);
	return (0);
}

static int	is_skippable_line(char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		return (1);
	return (0);
}

static int	parse_file(char *filename, t_scene *scene, int *read_flags)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		get_next_line(fd, &line);
		if (!line)
			break ;
		if (!is_skippable_line(line))
		{
			if (parse_line(line, scene, read_flags) < 0)
			{
				free(line);
				close(fd);
				return (-1);
			}
		}
		free(line);
	}
	close(fd);
	return (0);
}

t_scene	*parse_scene(char *filename)
{
	t_scene	*scene;
	int		read_flags;

	scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (!scene)
		return (NULL);
	read_flags = 0;
	if (parse_file(filename, scene, &read_flags) < 0)
	{
		free_scene(scene);
		return (NULL);
	}
	if (!validate_scene(read_flags))
	{
		free_scene(scene);
		return (NULL);
	}
	return (scene);
}
