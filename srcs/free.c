/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:57 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:42:24 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_2d_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_scene(t_scene *scene)
{
	t_obj	*current;
	t_obj	*next;

	if (scene)
	{
		if (scene->objects)
		{
			current = scene->objects;
			while (current)
			{
				next = current->next;
				free(current->obj_data);
				free(current);
				current = next;
			}
		}
		free(scene);
	}
	scene = NULL;
}

void	free_ctx(t_ctx *ctx)
{
	if (!ctx)
		return ;
	if (ctx->img)
		free(ctx->img);
	if (ctx->scene)
		free_scene(ctx->scene);
	free(ctx);
}
