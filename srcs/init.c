/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:26:43 by stakada           #+#    #+#             */
/*   Updated: 2025/10/20 12:17:52 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// TODO: delete debug statement
t_ctx	*init_ctx(char *filename)
{
	t_ctx	*ctx;

	ctx = (t_ctx *)ft_calloc(1, sizeof(t_ctx));
	if (!ctx)
		return (NULL);
	ctx->scene = parse_scene(filename);
	if (!ctx->scene)
	{
		free(ctx);
		return (NULL);
	}
	ctx->edit_mode = MODE_CAMERA;
	ctx->selected_obj = 0;
	print_scene(ctx->scene);
	return (ctx);
}
