/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 11:52:01 by stakada           #+#    #+#             */
/*   Updated: 2026/02/21 22:46:55 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_ctx *ctx)
{
	mlx_destroy_image(ctx->mlx, ctx->img->img);
	mlx_destroy_window(ctx->mlx, ctx->win);
	mlx_destroy_display(ctx->mlx);
	free_ctx(ctx);
	exit(0);
	return (0);
}

void	re_render(t_ctx *ctx)
{
	render_scene(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img->img, 0, 0);
	put_info(ctx);
}

static int	init_mlx_image(t_ctx *ctx)
{
	ctx->img = (t_img *)ft_calloc(1, sizeof(t_img));
	if (!ctx->img)
	{
		print_error(ERR_MSG_MALLOC);
		return (-1);
	}
	ctx->img->img = mlx_new_image(ctx->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!ctx->img->img)
	{
		print_error(ERR_MSG_MLX_IMAGE);
		return (-1);
	}
	ctx->img->addr = mlx_get_data_addr(ctx->img->img, &ctx->img->bpp,
			&ctx->img->line_length, &ctx->img->endian);
	return (0);
}

int	run_mlx(t_ctx *ctx)
{
	ctx->mlx = mlx_init();
	if (!ctx->mlx)
	{
		print_error(ERR_MSG_MLX_INIT);
		return (-1);
	}
	ctx->win = mlx_new_window(ctx->mlx, WIN_WIDTH, WIN_HEIGHT, PROGRAM);
	if (!ctx->win)
	{
		print_error(ERR_MSG_MLX_WINDOW);
		return (-1);
	}
	if (init_mlx_image(ctx) < 0)
	{
		mlx_destroy_window(ctx->mlx, ctx->win);
		return (-1);
	}
	render_scene(ctx);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img->img, 0, 0);
	put_info(ctx);
	mlx_hook(ctx->win, 2, 1L << 0, handle_key_input, ctx);
	mlx_hook(ctx->win, 17, 1L << 5, close_window, ctx);
	mlx_loop(ctx->mlx);
	return (0);
}
