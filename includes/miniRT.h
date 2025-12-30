/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:37:02 by stakada           #+#    #+#             */
/*   Updated: 2025/12/30 16:06:08 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "config.h"
# include "errors.h"
# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include "ft_printf.h"
# include <math.h>
# include <stdlib.h>
#include <float.h>

// check
int		check_args(int argc, char **argv);

// init
t_ctx	*init_ctx(char *filename);

// parsing
t_scene	*parse_scene(char *filename);
int		parse_ambient(char **elems, t_ambient *ambient, int *read_flags);
int		parse_camera(char **elems, t_camera *camera, int *read_flags);
int		parse_light(char **elems, t_light *light, int *read_flags);
int		parse_sphere(char **elems, t_object **objects, int *read_flags);
int		parse_plane(char **elems, t_object **objects, int *read_flags);
int		parse_cylinder(char **elems, t_object **objects, int *read_flags);

int		get_double(char *str, double *n);
int		parse_colors(char *str, t_color *color);
int		parse_vec3(char *str, t_vec3 *vec);

int		is_valid_num(const char *str);
int		is_valid_csv(const char *str);

int		validate_scene(int read_flags);
int		validate_double(double n, double min, double max);
int		validate_colors(t_color color);
int		validate_vec3(t_vec3 vec, double min, double max);

int		register_object(t_object **objects, t_obj_type type, void *obj);

// mlx
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	run_mlx(t_ctx *ctx);

// render
void	render_scene(t_ctx *ctx);

// math
t_vec3	vec3_cross(t_vec3 a, t_vec3 b);

// ray
int		intersect_sphere(t_vec3 origin, t_vec3 dir, t_sphere *sphere,
			double *distance, t_vec3 *normal);
int		intersect_plane(t_vec3 origin, t_vec3 dir, t_plane *plane,
			double *distance, t_vec3 *normal);
int		intersect_cylinder(t_vec3 origin, t_vec3 dir, t_cylinder *cylinder,
			double *distance, t_vec3 *normal);

// shading
int		get_background_color(t_scene *scene);
int		shade_color(t_scene *scene, t_color object_color, double diffuse);

// utils
int		count_array(char **array);
double	ft_strtod(const char *nptr, char **endptr);

// error
void	print_error(char *msg, ...);

// free
void	free_2d_array(char **array);
void	free_scene(t_scene *scene);
void	free_ctx(t_ctx *ctx);

// TODO: delete debug statement
// debug
void	print_scene(t_scene *scene);
void	print_objects(t_object *objects);
void	print_vec3(const char *prefix, t_vec3 vec);
void	print_color(const char *prefix, t_color color);

#endif
