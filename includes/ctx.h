/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:25:25 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 19:08:27 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CTX_H
# define CTX_H

# include "libft.h"

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

typedef enum e_edit_mode
{
	MODE_CAMERA,
	MODE_LIGHT,
	MODE_OBJECT,
}					t_edit_mode;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_ctx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_scene			*scene;
	t_edit_mode		edit_mode;
	t_obj			*selected_object;
}					t_ctx;

#endif