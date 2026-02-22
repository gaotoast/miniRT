/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:37:02 by stakada           #+#    #+#             */
/*   Updated: 2026/02/22 19:05:00 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "config.h"
# include "ctx.h"
# include "errors.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include "parsing.h"
# include "render.h"
# include <math.h>
# include <stdlib.h>

// check
int		check_args(int argc, char **argv);

// init
t_ctx	*init_ctx(char *filename);

// mlx
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		run_mlx(t_ctx *ctx);
int		close_window(t_ctx *ctx);
void	re_render(t_ctx *ctx);

// put_info
void	put_info(t_ctx *ctx);

// transform
void	translate_target(t_ctx *ctx, t_vec3 delta);
void	rotate_target(t_ctx *ctx, t_vec3 axis, double angle);
void	adjust_target(t_ctx *ctx, int sign, int height_mode);

// key_handler
int		handle_key_input(int keycode, t_ctx *ctx);

// utils
int		count_array(char **array);
int		count_objects(t_obj *objects);
double	ft_strtod(const char *nptr, char **endptr);
t_vec3	vec3_rotate(t_vec3 v, t_vec3 axis, double angle_deg);
t_vec3	front_normal(t_vec3 normal, t_vec3 ray_dir);
double	clamp01(double value);
int		clamp_color(double value);

// error
void	print_error(char *msg, ...);

// free
void	free_scene(t_scene *scene);
void	free_ctx(t_ctx *ctx);

#endif
