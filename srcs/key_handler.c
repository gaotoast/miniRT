/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:00:00 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/13 18:40:39 by stakada          ###   ########.fr       */
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
		ctx->selected_obj++;
		if (ctx->selected_obj >= count_objects(ctx->scene->objects))
			ctx->selected_obj = 0;
	}
}

static int	get_move_delta(int keycode, t_vec3 *delta)
{
	if (keycode == KEY_W)
		*delta = vec3(0, MOVE_STEP, 0);
	else if (keycode == KEY_S)
		*delta = vec3(0, -MOVE_STEP, 0);
	else if (keycode == KEY_A)
		*delta = vec3(-MOVE_STEP, 0, 0);
	else if (keycode == KEY_D)
		*delta = vec3(MOVE_STEP, 0, 0);
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
		*angle = -ROTATE_STEP;
	}
	else if (keycode == KEY_RIGHT)
	{
		*axis = vec3(0, 1, 0);
		*angle = ROTATE_STEP;
	}
	else
		return (0);
	return (1);
}

static double	get_adjust_step(t_edit_mode mode)
{
	if (mode == MODE_CAMERA)
		return (FOV_STEP);
	else if (mode == MODE_LIGHT)
		return (BRIGHT_STEP);
	return (SIZE_STEP);
}

int	handle_key_input(int keycode, t_ctx *ctx)
{
	t_vec3	delta;
	t_vec3	axis;
	double	angle;
	double	step;

	if (keycode == ESC_KEY)
		return (close_window(ctx), 0);
	handle_mode_switch(keycode, ctx);
	step = get_adjust_step(ctx->edit_mode);
	if (get_move_delta(keycode, &delta))
		translate_target(ctx, delta);
	else if (get_rotate_params(keycode, &axis, &angle))
		rotate_target(ctx, axis, angle);
	else if (keycode == KEY_PLUS)
		adjust_target(ctx, step, 0);
	else if (keycode == KEY_MINUS)
		adjust_target(ctx, -step, 0);
	else if (keycode == KEY_H && ctx->edit_mode == MODE_OBJECT)
		adjust_target(ctx, SIZE_STEP, 1);
	re_render(ctx);
	return (0);
}
