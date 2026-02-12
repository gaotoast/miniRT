/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:12:25 by stakada           #+#    #+#             */
/*   Updated: 2026/02/12 21:42:47 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "ctx.h"

t_scene	*parse_scene(char *filename);
int		parse_ambient(char **elems, t_ambient *ambient, int *read_flags);
int		parse_camera(char **elems, t_camera *camera, int *read_flags);
int		parse_light(char **elems, t_light *light, int *read_flags);
int		parse_sphere(char **elems, t_obj **objects, int *read_flags);
int		parse_plane(char **elems, t_obj **objects, int *read_flags);
int		parse_cylinder(char **elems, t_obj **objects, int *read_flags);

int		get_double(const char *str, double *num, char **endptr);
int		parse_colors(char *str, t_color *color);
int		parse_vec3(char *str, t_vec3 *vec);

int		is_valid_num(const char *str);
int		is_valid_csv(const char *str);

int		validate_scene(int read_flags);
int		validate_double(double n, double min, double max);
int		validate_colors(t_color color);
int		validate_vec3(t_vec3 vec, double min, double max);

int		register_object(t_obj **objects, t_obj_type type, void *obj);

#endif