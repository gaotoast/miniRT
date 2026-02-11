/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:37:02 by stakada           #+#    #+#             */
/*   Updated: 2026/02/11 22:26:53 by stakada          ###   ########.fr       */
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
# include <float.h>
# include <math.h>
# include <stdlib.h>

// check
int		check_args(int argc, char **argv);

// init
t_ctx	*init_ctx(char *filename);

// mlx
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	run_mlx(t_ctx *ctx);
int		close_window(t_ctx *ctx);
void	re_render(t_ctx *ctx);

// transform
void	translate_camera(t_camera *camera, t_vec3 delta);
void	rotate_camera(t_camera *camera, t_vec3 axis, double angle);
void	adjust_fov(t_camera *camera, double delta);
void	translate_light(t_light *light, t_vec3 delta);
void	adjust_brightness(t_light *light, double delta);
void	translate_object(t_obj *objects, int index, t_vec3 delta);
void	rotate_object(t_obj *objects, int index, t_vec3 axis, double angle);
void	resize_object(t_obj *objects, int index, double delta, int h_mode);
int		count_objects(t_obj *objects);

// key_handler
int		handle_key_input(int keycode, t_ctx *ctx);

// mouse handler
int		handle_mouse_input(int button, int x, int y, t_ctx *ctx);

// utils
int		count_array(char **array);
double	ft_strtod(const char *nptr, char **endptr);
t_vec3	vec3_rotate(t_vec3 v, t_vec3 axis, double angle_deg);
t_vec3	front_normal(t_vec3 normal, t_vec3 ray_dir);
double	clamp01(double value);
int		clamp_color(double value);

// error
void	print_error(char *msg, ...);

// free
void	free_2d_array(char **array);
void	free_scene(t_scene *scene);
void	free_ctx(t_ctx *ctx);

// TODO: delete debug statement
// debug
void	print_scene(t_scene *scene);
void	print_objects(t_obj *objects);
void	print_vec3(const char *prefix, t_vec3 vec);
void	print_color(const char *prefix, t_color color);

#endif
