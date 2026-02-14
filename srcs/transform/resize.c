/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:19:58 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 23:44:56 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	add_clamped(double *value, double delta, double min, double max)
{
	if (!value)
		return ;
	*value += delta;
	if (*value < min)
		*value = min;
	if (max > 0 && *value > max)
		*value = max;
}

static double	*get_obj_size(t_obj *obj, int height_mode)
{
	if (!obj || !obj->obj_data)
		return (NULL);
	if (obj->type == SPHERE)
		return (&((t_sphere *)obj->obj_data)->diameter);
	else if (obj->type == CYLINDER)
	{
		if (height_mode)
			return (&((t_cylinder *)obj->obj_data)->height);
		return (&((t_cylinder *)obj->obj_data)->diameter);
	}
	return (NULL);
}

void	adjust_target(t_ctx *ctx, int sign, int height_mode)
{
	double	*target;

	if (ctx->edit_mode == MODE_CAMERA)
	{
		add_clamped(&ctx->scene->camera.fov_deg, sign * FOV_STEP, 1.0, 179.0);
		return ;
	}
	else if (ctx->edit_mode == MODE_LIGHT)
	{
		add_clamped(&ctx->scene->light.brightness, sign * BRIGHT_STEP, 0.0,
			1.0);
		return ;
	}
	target = get_obj_size(ctx->selected_object, height_mode);
	if (target)
		add_clamped(target, sign * SIZE_STEP, MIN_SIZE, 0);
}
