/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:52:01 by stakada           #+#    #+#             */
/*   Updated: 2026/01/10 19:08:55 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

// TODO: Linux needs mlx_destroy_display() after mlx_destroy_window()
int	close_window(t_ctx *ctx)
{
	mlx_destroy_image(ctx->mlx, ctx->img->img);
	mlx_destroy_window(ctx->mlx, ctx->win);
	// mlx_destroy_display();
	free_ctx(ctx);
	exit(0);
	return (0);
}

static void	re_render(t_ctx *ctx)
{
	render_scene(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img->img, 0, 0);
}

int	handle_key_input(int keycode, t_ctx *ctx)
{
	if (keycode == ESC_KEY)
		close_window(ctx);
	else
	{
		process_key_input(keycode, ctx);
		re_render(ctx);
	}
	return (0);
}

int	handle_mouse_input(int button, int x, int y, t_ctx *ctx)
{
	(void)x;
	(void)y;
	process_mouse_input(button, ctx);
	re_render(ctx);
	return (0);
}

void	run_mlx(t_ctx *ctx)
{
	ctx->mlx = mlx_init();
	ctx->win = mlx_new_window(ctx->mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	ctx->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!ctx->img)
	{
		print_error(ERR_MSG_MALLOC);
		close_window(ctx);
		return ;
	}
	ctx->img->img = mlx_new_image(ctx->mlx, WIN_WIDTH, WIN_HEIGHT);
	ctx->img->addr = mlx_get_data_addr(ctx->img->img, &ctx->img->bpp,
			&ctx->img->line_length, &ctx->img->endian);
	render_scene(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img->img, 0, 0);
	mlx_hook(ctx->win, 2, 1L << 0, handle_key_input, ctx);
	mlx_hook(ctx->win, 4, 1L << 2, handle_mouse_input, ctx);
	mlx_hook(ctx->win, 17, 1L << 5, close_window, ctx);
	mlx_loop(ctx->mlx);
}
