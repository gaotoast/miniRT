/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:37:02 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 17:55:27 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "config.h"
# include "errors.h"
# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include <math.h>
# include <stdlib.h>

// check
int		check_args(int argc, char **argv);

// init
t_ctx	*init(char *filename);

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

int		validate_scene(int read_flags);
int		validate_elements(char *err_msg, char *identifier);
int		validate_double(double n, double min, double max);
int		validate_colors(t_color color);
int		validate_vec3(t_vec3 vec, double min, double max);

int		register_object(t_object **objects, t_obj_type type, void *obj);

// utils
int		count_array(char **array);
double	ft_strtod(const char *nptr, char **endptr);

// error
void	print_error(char *msg, ...);

// free
void	free_2d_array(char **array);
void	free_scene(t_scene *scene);
void	free_ctx(t_ctx *ctx);

// debug
void	debug_scene(t_scene *scene);

#endif