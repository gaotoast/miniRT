/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:12:25 by stakada           #+#    #+#             */
/*   Updated: 2026/02/11 21:19:06 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_ambient
{
	double			ratio;
	t_color			color;
}					t_ambient;

typedef struct s_camera
{
	t_vec3			position;
	t_vec3			direction;
	double			fov_deg;
}					t_camera;

typedef struct s_light
{
	t_vec3			position;
	double			brightness;
	t_color			color;
}					t_light;

typedef struct s_sphere
{
	t_vec3			center;
	double			diameter;
	t_color			color;
}					t_sphere;

typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
}					t_plane;

typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			axis;
	double			diameter;
	double			height;
	t_color			color;
}					t_cylinder;

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}					t_obj_type;

typedef struct s_obj
{
	t_obj_type		type;
	void			*obj_data;
	struct s_obj	*next;
}					t_obj;

typedef struct s_scene
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_obj			*objects;
}					t_scene;

t_scene				*parse_scene(char *filename);
int					parse_ambient(char **elems, t_ambient *ambient,
						int *read_flags);
int					parse_camera(char **elems, t_camera *camera,
						int *read_flags);
int					parse_light(char **elems, t_light *light, int *read_flags);
int					parse_sphere(char **elems, t_obj **objects,
						int *read_flags);
int					parse_plane(char **elems, t_obj **objects, int *read_flags);
int					parse_cylinder(char **elems, t_obj **objects,
						int *read_flags);

int					get_double(char *str, double *n);
int					parse_colors(char *str, t_color *color);
int					parse_vec3(char *str, t_vec3 *vec);

int					is_valid_num(const char *str);
int					is_valid_csv(const char *str);

int					validate_scene(int read_flags);
int					validate_double(double n, double min, double max);
int					validate_colors(t_color color);
int					validate_vec3(t_vec3 vec, double min, double max);

int					register_object(t_obj **objects, t_obj_type type,
						void *obj);

#endif