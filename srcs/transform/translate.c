/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:18:14 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 19:15:07 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vec3	*get_obj_position(t_obj *obj)
{
	if (obj->type == SPHERE)
		return (&((t_sphere *)obj->obj_data)->center);
	else if (obj->type == PLANE)
		return (&((t_plane *)obj->obj_data)->point);
	else if (obj->type == CYLINDER)
		return (&((t_cylinder *)obj->obj_data)->center);
	return (NULL);
}

static t_vec3	*get_target_position(t_ctx *ctx)
{
	if (ctx->edit_mode == MODE_CAMERA)
		return (&ctx->scene->camera.position);
	else if (ctx->edit_mode == MODE_LIGHT)
		return (&ctx->scene->light.position);
	if (ctx->selected_object)
		return (get_obj_position(ctx->selected_object));
	return (NULL);
}

void	translate_target(t_ctx *ctx, t_vec3 delta)
{
	t_vec3	*pos;

	pos = get_target_position(ctx);
	if (pos)
		*pos = vec3_add(*pos, delta);
}
