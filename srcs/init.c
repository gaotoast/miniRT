/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:26:43 by stakada           #+#    #+#             */
/*   Updated: 2026/02/14 21:49:53 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ctx	*init_ctx(char *filename)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)ft_calloc(1, sizeof(t_ctx));
	if (!ctx)
	{
		print_error(ERR_MSG_MALLOC);
		return (NULL);
	}
	ctx->scene = parse_scene(filename);
	if (!ctx->scene)
	{
		free(ctx);
		return (NULL);
	}
	ctx->edit_mode = MODE_CAMERA;
	ctx->selected_object = ctx->scene->objects;
	return (ctx);
}
