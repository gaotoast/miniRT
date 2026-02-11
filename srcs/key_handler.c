/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:00:00 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/11 21:02:12 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	count_objects(t_obj *objects)
{
	int		count;
	t_obj	*obj;

	count = 0;
	obj = objects;
	while (obj)
	{
		count++;
		obj = obj->next;
	}
	return (count);
}

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

static void	handle_camera_keys(int keycode, t_ctx *ctx)
{
	t_camera	*cam;

	cam = &ctx->scene->camera;
	if (keycode == KEY_W)
		translate_camera(cam, vec3(0, MOVE_STEP, 0));
	else if (keycode == KEY_S)
		translate_camera(cam, vec3(0, -MOVE_STEP, 0));
	else if (keycode == KEY_A)
		translate_camera(cam, vec3(-MOVE_STEP, 0, 0));
	else if (keycode == KEY_D)
		translate_camera(cam, vec3(MOVE_STEP, 0, 0));
	else if (keycode == KEY_Q)
		translate_camera(cam, vec3(0, 0, -MOVE_STEP));
	else if (keycode == KEY_E)
		translate_camera(cam, vec3(0, 0, MOVE_STEP));
	else if (keycode == KEY_UP)
		rotate_camera(cam, vec3(1, 0, 0), -ROTATE_STEP);
	else if (keycode == KEY_DOWN)
		rotate_camera(cam, vec3(1, 0, 0), ROTATE_STEP);
	else if (keycode == KEY_LEFT)
		rotate_camera(cam, vec3(0, 1, 0), -ROTATE_STEP);
	else if (keycode == KEY_RIGHT)
		rotate_camera(cam, vec3(0, 1, 0), ROTATE_STEP);
	else if (keycode == KEY_PLUS)
		adjust_fov(cam, FOV_STEP);
	else if (keycode == KEY_MINUS)
		adjust_fov(cam, -FOV_STEP);
}

static void	handle_light_keys(int keycode, t_ctx *ctx)
{
	t_light	*light;

	light = &ctx->scene->light;
	if (keycode == KEY_W)
		translate_light(light, vec3(0, MOVE_STEP, 0));
	else if (keycode == KEY_S)
		translate_light(light, vec3(0, -MOVE_STEP, 0));
	else if (keycode == KEY_A)
		translate_light(light, vec3(-MOVE_STEP, 0, 0));
	else if (keycode == KEY_D)
		translate_light(light, vec3(MOVE_STEP, 0, 0));
	else if (keycode == KEY_Q)
		translate_light(light, vec3(0, 0, -MOVE_STEP));
	else if (keycode == KEY_E)
		translate_light(light, vec3(0, 0, MOVE_STEP));
	else if (keycode == KEY_PLUS)
		adjust_brightness(light, BRIGHT_STEP);
	else if (keycode == KEY_MINUS)
		adjust_brightness(light, -BRIGHT_STEP);
}

static void	handle_object_keys(int keycode, t_ctx *ctx)
{
	t_obj	*objs;
	int		idx;

	objs = ctx->scene->objects;
	idx = ctx->selected_obj;
	if (keycode == KEY_W)
		translate_object(objs, idx, vec3(0, MOVE_STEP, 0));
	else if (keycode == KEY_S)
		translate_object(objs, idx, vec3(0, -MOVE_STEP, 0));
	else if (keycode == KEY_A)
		translate_object(objs, idx, vec3(-MOVE_STEP, 0, 0));
	else if (keycode == KEY_D)
		translate_object(objs, idx, vec3(MOVE_STEP, 0, 0));
	else if (keycode == KEY_Q)
		translate_object(objs, idx, vec3(0, 0, -MOVE_STEP));
	else if (keycode == KEY_E)
		translate_object(objs, idx, vec3(0, 0, MOVE_STEP));
	else if (keycode == KEY_UP)
		rotate_object(objs, idx, vec3(1, 0, 0), -ROTATE_STEP);
	else if (keycode == KEY_DOWN)
		rotate_object(objs, idx, vec3(1, 0, 0), ROTATE_STEP);
	else if (keycode == KEY_LEFT)
		rotate_object(objs, idx, vec3(0, 1, 0), -ROTATE_STEP);
	else if (keycode == KEY_RIGHT)
		rotate_object(objs, idx, vec3(0, 1, 0), ROTATE_STEP);
	else if (keycode == KEY_PLUS)
		resize_object(objs, idx, SIZE_STEP, 0);
	else if (keycode == KEY_MINUS)
		resize_object(objs, idx, -SIZE_STEP, 0);
	else if (keycode == KEY_H)
		resize_object(objs, idx, SIZE_STEP, 1);
}

int	handle_key_input(int keycode, t_ctx *ctx)
{
	if (keycode == ESC_KEY)
		close_window(ctx);
	else
	{
		handle_mode_switch(keycode, ctx);
		if (ctx->edit_mode == MODE_CAMERA)
			handle_camera_keys(keycode, ctx);
		else if (ctx->edit_mode == MODE_LIGHT)
			handle_light_keys(keycode, ctx);
		else if (ctx->edit_mode == MODE_OBJECT)
			handle_object_keys(keycode, ctx);
		re_render(ctx);
	}
	return (0);
}
