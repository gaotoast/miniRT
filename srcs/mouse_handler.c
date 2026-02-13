/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:15:37 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 18:41:57 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	get_scroll_sign(int button)
{
	if (button == MOUSE_SCROLL_UP)
		return (1.0);
	else if (button == MOUSE_SCROLL_DOWN)
		return (-1.0);
	return (0.0);
}

static double	get_adjust_step(t_edit_mode mode)
{
	if (mode == MODE_CAMERA)
		return (FOV_STEP);
	else if (mode == MODE_LIGHT)
		return (BRIGHT_STEP);
	return (SIZE_STEP);
}

int	handle_mouse_input(int button, int x, int y, t_ctx *ctx)
{
	double	sign;
	double	step;

	(void)x;
	(void)y;
	sign = get_scroll_sign(button);
	step = get_adjust_step(ctx->edit_mode);
	if (sign != 0.0)
		adjust_target(ctx, step * sign, 0);
	else if (ctx->edit_mode == MODE_OBJECT)
	{
		if (button == MOUSE_LEFT)
			adjust_target(ctx, SIZE_STEP, 1);
		else if (button == MOUSE_RIGHT)
			adjust_target(ctx, -SIZE_STEP, 1);
	}
	re_render(ctx);
	return (0);
}
