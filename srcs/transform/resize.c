/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:19:58 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 18:39:56 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	add_clamped(double *value, double delta, double min, double max)
{
	*value += delta;
	if (*value < min)
		*value = min;
	if (max > 0 && *value > max)
		*value = max;
}

static double	*get_obj_size(t_obj *obj, int height_mode)
{
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

void	adjust_target(t_ctx *ctx, double delta, int height_mode)
{
	t_obj	*obj;
	double	*target;
	int		i;

	if (ctx->edit_mode == MODE_CAMERA)
		return (add_clamped(&ctx->scene->camera.fov_deg, delta, 1.0, 179.0));
	else if (ctx->edit_mode == MODE_LIGHT)
		return (add_clamped(&ctx->scene->light.brightness, delta, 0.0, 1.0));
	obj = ctx->scene->objects;
	i = 0;
	while (obj && i < ctx->selected_obj)
	{
		obj = obj->next;
		i++;
	}
	target = get_obj_size(obj, height_mode);
	if (target)
		add_clamped(target, delta, MIN_SIZE, 0);
}
