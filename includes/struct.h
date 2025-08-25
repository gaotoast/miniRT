/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:36:57 by stakada           #+#    #+#             */
/*   Updated: 2025/08/22 13:36:59 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/**
 * @brief Represents a 3D vector for coordinates, directions, etc.
 */
typedef struct s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vec3;

/**
 * @brief Represents a color using RGB values, ranging from 0.0 to 1.0.
 */
typedef struct s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

/**
 * @brief Defines the ambient light in the scene.
 * There is only one ambient light declaration in the scene file.
 */
typedef struct s_ambient
{
	double			ratio;
	t_color			color;
}					t_ambient;

/**
 * @brief Defines the camera's properties and position in the scene.
 * There is only one camera declaration in the scene file.
 */
typedef struct s_camera
{
	t_vec3			origin;
	t_vec3			direction;
	double			fov;
}					t_camera;

/**
 * @brief Defines a light source in the scene.
 * For the mandatory part, there is only one light source.
 */
typedef struct s_light
{
	t_vec3			origin;
	double			brightness;
	t_color			color;
}					t_light;

/**
 * @brief Enum for identifying the type of a geometric object.
 */
typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}					t_obj_type;

/**
 * @brief Properties specific to a sphere object.
 */
typedef struct s_sphere
{
	t_vec3			center;
	double			diameter;
}					t_sphere;

/**
 * @brief Properties specific to a plane object.
 */
typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
}					t_plane;

/**
 * @brief Properties specific to a cylinder object.
 */
typedef struct s_cylinder
{
	t_vec3			center;
	t_vec3			axis;
	double			diameter;
	double			height;
}					t_cylinder;

/**
 * @brief A generic object structure, used to create a linked list of all
 * objects in the scene.
 * @param properties A void pointer to the specific object's struct (e.g.,
	s_sphere).
 */
typedef struct s_object
{
	t_obj_type		type;
	void			*properties;
	t_color			color;
	struct s_object	*next;
}					t_object;

/**
 * @brief Holds all parsed data that defines the scene's contents.
 */
typedef struct s_scene
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_object		*objects;
}					t_scene;

/**
 * @brief Stores data related to a MiniLibX image buffer.
 * This helps manage the image where the scene will be rendered.
 */
typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

/**
 * @brief Main program structure, holding MiniLibX pointers and a pointer
 * to the scene data. This acts as the central hub for the application.
 */
typedef struct s_ctx
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_scene			*scene;
}					t_ctx;

#endif