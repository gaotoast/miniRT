/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:15:37 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:15:53 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	handle_mouse_resize(int button, t_ctx *ctx, double step)
{
	if (ctx->edit_mode == MODE_CAMERA)
	{
		if (button == MOUSE_SCROLL_UP)
			adjust_fov(&ctx->scene->camera, step);
		else if (button == MOUSE_SCROLL_DOWN)
			adjust_fov(&ctx->scene->camera, -step);
	}
	else if (ctx->edit_mode == MODE_LIGHT)
	{
		if (button == MOUSE_SCROLL_UP)
			adjust_brightness(&ctx->scene->light, BRIGHT_STEP);
		else if (button == MOUSE_SCROLL_DOWN)
			adjust_brightness(&ctx->scene->light, -BRIGHT_STEP);
	}
	else if (ctx->edit_mode == MODE_OBJECT)
	{
		if (button == MOUSE_SCROLL_UP)
			resize_object(ctx->scene->objects, ctx->selected_obj, SIZE_STEP, 0);
		else if (button == MOUSE_SCROLL_DOWN)
			resize_object(ctx->scene->objects, ctx->selected_obj, -SIZE_STEP,
				0);
		else if (button == MOUSE_LEFT)
			resize_object(ctx->scene->objects, ctx->selected_obj, SIZE_STEP, 1);
		else if (button == MOUSE_RIGHT)
			resize_object(ctx->scene->objects, ctx->selected_obj, -SIZE_STEP,
				1);
	}
}

void	process_mouse_input(int button, t_ctx *ctx)
{
	handle_mouse_resize(button, ctx, FOV_STEP);
}
