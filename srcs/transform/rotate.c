/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:19:29 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 23:45:35 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vec3	*get_obj_direction(t_obj *obj)
{
	if (!obj || !obj->obj_data)
		return (NULL);
	if (obj->type == PLANE)
		return (&((t_plane *)obj->obj_data)->normal);
	else if (obj->type == CYLINDER)
		return (&((t_cylinder *)obj->obj_data)->axis);
	return (NULL);
}

static t_vec3	*get_target_direction(t_ctx *ctx)
{
	if (!ctx)
		return (NULL);
	if (ctx->edit_mode == MODE_CAMERA)
		return (&ctx->scene->camera.direction);
	else if (ctx->edit_mode == MODE_LIGHT)
		return (NULL);
	if (ctx->selected_object)
		return (get_obj_direction(ctx->selected_object));
	return (NULL);
}

void	rotate_target(t_ctx *ctx, t_vec3 axis, double angle)
{
	t_vec3	*dir;

	dir = get_target_direction(ctx);
	if (dir)
		*dir = vec3_normalize(vec3_rotate(*dir, axis, angle));
}
