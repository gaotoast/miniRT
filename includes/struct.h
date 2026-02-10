/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:36:57 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 15:41:27 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	t_vec3			position;
	t_vec3			direction;
	double			fov_deg;
}					t_camera;

typedef struct s_camera_frame
{
	// coordinates
	t_vec3			origin;
	// orientation
	t_vec3			forward;
	t_vec3			right;
	t_vec3			up;
	// viewport
	double			half_width;
	double			half_height;
}					t_camera_frame;

/**
 * @brief Defines a light source in the scene.
 * For the mandatory part, there is only one light source.
 */
typedef struct s_light
{
	t_vec3			position;
	double			brightness;
	t_color			color;
}					t_light;

/**
 * @brief Enum for identifying the edit mode.
 */
typedef enum e_edit_mode
{
	MODE_CAMERA,
	MODE_LIGHT,
	MODE_OBJECT,
}					t_edit_mode;

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
	t_color			color;
}					t_sphere;

/**
 * @brief Properties specific to a plane object.
 */
typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
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
	t_color			color;
}					t_cylinder;

/**
 * @brief A generic object structure, used to create a linked list of all
 * objects in the scene.
 */
typedef struct s_object
{
	t_obj_type		type;
	void			*obj_data;
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
	t_edit_mode		edit_mode;
	int				selected_obj;
}					t_ctx;

/**
 * @brief Stores information about a ray-object intersection.
 */
typedef struct s_hit
{
	t_object		*object;
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
	double			distance;
}					t_hit;

#endif
