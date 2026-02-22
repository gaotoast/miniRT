/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 00:30:30 by stakada           #+#    #+#             */
/*   Updated: 2026/02/15 02:18:32 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static char	*get_obj_name(t_obj_type type)
{
	if (type == SPHERE)
		return ("Sphere");
	if (type == PLANE)
		return ("Plane");
	if (type == CYLINDER)
		return ("Cylinder");
	return ("Unknown");
}

static void	put_camera_info(t_ctx *ctx)
{
	if (!ctx)
		return ;
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 4, TEXT_COLOR,
		"Mode: Camera Control");
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 5, TEXT_COLOR,
		" Move: W, A, S, D, Q, E");
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 6, TEXT_COLOR,
		" Rotate: Arrow keys");
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 7, TEXT_COLOR,
		" FOV: + (Increase), - (Decrease)");
}

static void	put_light_info(t_ctx *ctx)
{
	if (!ctx)
		return ;
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 4, TEXT_COLOR,
		"Mode: Light Control");
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 5, TEXT_COLOR,
		" Move: W, A, S, D, Q, E");
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 6, TEXT_COLOR,
		" Brightness: + (Increase), - (Decrease)");
}

static void	put_object_info(t_ctx *ctx)
{
	int		line;
	char	mode_info[100];

	if (!ctx || !ctx->selected_object)
		return ;
	line = 4;
	ft_strlcpy(mode_info, "Mode: Object Control (", 100);
	ft_strlcat(mode_info, get_obj_name(ctx->selected_object->type), 100);
	ft_strlcat(mode_info, ")", 100);
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * line++, TEXT_COLOR,
		mode_info);
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * line++, TEXT_COLOR,
		" Switch Object: TAB");
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * line++, TEXT_COLOR,
		" Move: W, A, S, D, Q, E");
	if (ctx->selected_object->type != SPHERE)
		mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * line++,
			TEXT_COLOR, " Rotate: Arrow keys");
	if (ctx->selected_object->type == SPHERE
		|| ctx->selected_object->type == CYLINDER)
		mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * line++,
			TEXT_COLOR, " Diameter: + (Increase), - (Decrease)");
	if (ctx->selected_object->type == CYLINDER)
		mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * line++,
			TEXT_COLOR, " Height: H (Increase), J (Decrease)");
}

void	put_info(t_ctx *ctx)
{
	if (!ctx)
		return ;
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 1, TEXT_COLOR,
		"Change Mode: 1 (Camera), 2 (Light), 3 (Object)");
	mlx_string_put(ctx->mlx, ctx->win, MARGIN, LINE_HEIGHT * 2, TEXT_COLOR,
		"Quit: ESC");
	if (ctx->edit_mode == MODE_CAMERA)
		put_camera_info(ctx);
	else if (ctx->edit_mode == MODE_LIGHT)
		put_light_info(ctx);
	else
		put_object_info(ctx);
}
