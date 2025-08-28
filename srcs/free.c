/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:17:57 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 16:51:48 by stakada          ###   ########.fr       */
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
	t_object	*current;
	t_object	*next;

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
}

void	free_img(t_img *img)
{
	if (img->img)
		free(img->img);
	if (img->addr)
		free(img->addr);
}

void	free_ctx(t_ctx *ctx)
{
	if (ctx->mlx)
		free(ctx->mlx);
	if (ctx->win)
		free(ctx->win);
	if (ctx->img)
		free_img(ctx->img);
	if (ctx->scene)
		free_scene(ctx->scene);
}
