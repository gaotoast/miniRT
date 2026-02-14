/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_context.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 19:01:06 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 19:14:39 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static const char	*get_edit_mode_str(t_edit_mode mode)
{
	if (mode == MODE_CAMERA)
		return ("Camera");
	else if (mode == MODE_LIGHT)
		return ("Light");
	else if (mode == MODE_OBJECT)
		return ("Object");
	return ("Unknown");
}

static const char	*get_selected_object_str(t_obj_type type)
{
	if (type == SPHERE)
		return ("Sphere");
	else if (type == PLANE)
		return ("Plane");
	else if (type == CYLINDER)
		return ("Cylinder");
	return ("Unknown");
}

void	print_context(t_ctx *ctx)
{
	if (!ctx)
	{
		printf("Error: Context is NULL\n");
		return ;
	}
	printf("\n===== Context Information =====\n\n");
	printf("Edit Mode: %s\n", get_edit_mode_str(ctx->edit_mode));
	if (ctx->edit_mode == MODE_OBJECT && ctx->selected_object)
		printf("Selected Object Type: %s\n",
			get_selected_object_str(ctx->selected_object->type));
	printf("\n--- Scene Information ---\n\n");
	print_scene(ctx->scene);
	printf("\n=============================\n\n");
}
