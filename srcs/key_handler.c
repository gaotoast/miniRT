/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:00:00 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/23 10:43:59 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	handle_mode_switch(int keycode, t_ctx *ctx)
{
	if (keycode == KEY_1)
		ctx->edit_mode = MODE_CAMERA;
	else if (keycode == KEY_2)
		ctx->edit_mode = MODE_LIGHT;
	else if (keycode == KEY_3)
		ctx->edit_mode = MODE_OBJECT;
	else if (keycode == KEY_TAB && ctx->edit_mode == MODE_OBJECT)
	{
		if (ctx->selected_object && ctx->selected_object->next)
			ctx->selected_object = ctx->selected_object->next;
		else
			ctx->selected_object = ctx->scene->objects;
	}
}

static int	get_move_delta(int keycode, t_vec3 *delta)
{
	if (keycode == KEY_W)
		*delta = vec3(0, MOVE_STEP, 0);
	else if (keycode == KEY_S)
		*delta = vec3(0, -MOVE_STEP, 0);
	else if (keycode == KEY_A)
		*delta = vec3(MOVE_STEP, 0, 0);
	else if (keycode == KEY_D)
		*delta = vec3(-MOVE_STEP, 0, 0);
	else if (keycode == KEY_Q)
		*delta = vec3(0, 0, -MOVE_STEP);
	else if (keycode == KEY_E)
		*delta = vec3(0, 0, MOVE_STEP);
	else
		return (0);
	return (1);
}

static int	get_rotate_params(int keycode, t_vec3 *axis, double *angle)
{
	if (keycode == KEY_UP)
	{
		*axis = vec3(1, 0, 0);
		*angle = -ROTATE_STEP;
	}
	else if (keycode == KEY_DOWN)
	{
		*axis = vec3(1, 0, 0);
		*angle = ROTATE_STEP;
	}
	else if (keycode == KEY_LEFT)
	{
		*axis = vec3(0, 1, 0);
		*angle = ROTATE_STEP;
	}
	else if (keycode == KEY_RIGHT)
	{
		*axis = vec3(0, 1, 0);
		*angle = -ROTATE_STEP;
	}
	else
		return (0);
	return (1);
}

static int	get_adjust_params(int keycode, int *sign, int *height_mode)
{
	if (keycode == KEY_P)
	{
		*sign = 1;
		*height_mode = 0;
	}
	else if (keycode == KEY_M)
	{
		*sign = -1;
		*height_mode = 0;
	}
	else if (keycode == KEY_H)
	{
		*sign = 1;
		*height_mode = 1;
	}
	else if (keycode == KEY_J)
	{
		*sign = -1;
		*height_mode = 1;
	}
	else
		return (0);
	return (1);
}

int	handle_key_input(int keycode, t_ctx *ctx)
{
	t_vec3	delta;
	t_vec3	axis;
	double	angle;
	int		sign;
	int		height_mode;

	if (keycode == ESC_KEY)
	{
		close_window(ctx);
		return (0);
	}
	handle_mode_switch(keycode, ctx);
	if (get_move_delta(keycode, &delta))
		translate_target(ctx, delta);
	else if (get_rotate_params(keycode, &axis, &angle))
		rotate_target(ctx, axis, angle);
	else if (get_adjust_params(keycode, &sign, &height_mode))
		adjust_target(ctx, sign, height_mode);
	re_render(ctx);
	return (0);
}
