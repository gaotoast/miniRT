/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:30:53 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 16:34:24 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/**
 * @brief Helper function to display vector values
 */
static void	debug_vec3(char *prefix, t_vec3 vec)
{
	printf("%s: (%f, %f, %f)\n", prefix, vec.x, vec.y, vec.z);
}

/**
 * @brief Helper function to display color values
 */
static void	debug_color(char *prefix, t_color color)
{
	printf("%s: R=%f, G=%f, B=%f\n", prefix, color.r, color.g, color.b);
}

/**
 * @brief Function to display ambient light information
 */
static void	debug_ambient(t_ambient ambient)
{
	printf("\n===== AMBIENT LIGHT =====\n");
	printf("Ratio: %f\n", ambient.ratio);
	debug_color("Color", ambient.color);
}

/**
 * @brief Function to display camera information
 */
static void	debug_camera(t_camera camera)
{
	printf("\n===== CAMERA =====\n");
	debug_vec3("Position", camera.position);
	debug_vec3("Direction", camera.direction);
	printf("FOV: %f\n", camera.fov);
}

/**
 * @brief Function to display light source information
 */
static void	debug_light(t_light light)
{
	printf("\n===== LIGHT SOURCE =====\n");
	debug_vec3("Position", light.position);
	printf("Brightness: %f\n", light.brightness);
	debug_color("Color", light.color);
}

/**
 * @brief Function to display sphere object information
 */
static void	debug_sphere(t_sphere *sphere)
{
	printf("Type: Sphere\n");
	debug_vec3("Center", sphere->center);
	printf("Diameter: %f\n", sphere->diameter);
	debug_color("Color", sphere->color);
}

/**
 * @brief Function to display plane object information
 */
static void	debug_plane(t_plane *plane)
{
	printf("Type: Plane\n");
	debug_vec3("Point", plane->point);
	debug_vec3("Normal", plane->normal);
	debug_color("Color", plane->color);
}

/**
 * @brief Function to display cylinder object information
 */
static void	debug_cylinder(t_cylinder *cylinder)
{
	printf("Type: Cylinder\n");
	debug_vec3("Center", cylinder->center);
	debug_vec3("Axis", cylinder->axis);
	printf("Diameter: %f\n", cylinder->diameter);
	printf("Height: %f\n", cylinder->height);
	debug_color("Color", cylinder->color);
}

/**
 * @brief Function to display object list
 */
static void	debug_objects(t_object *objects)
{
	int	count;

	count = 0;
	printf("\n===== OBJECTS =====\n");
	while (objects)
	{
		printf("\nObject %d\n", ++count);
		if (objects->type == SPHERE)
			debug_sphere((t_sphere *)objects->obj_data);
		else if (objects->type == PLANE)
			debug_plane((t_plane *)objects->obj_data);
		else if (objects->type == CYLINDER)
			debug_cylinder((t_cylinder *)objects->obj_data);
		objects = objects->next;
	}
	printf("\nTotal objects: %d\n", count);
}

/**
 * @brief Function to display information about the entire scene
 * @param scene Pointer to the scene structure to be displayed
 */
void	debug_scene(t_scene *scene)
{
	if (!scene)
	{
		printf("Error: Scene is NULL\n");
		return ;
	}
	printf("\n======= SCENE DEBUG INFORMATION =======\n");
	debug_ambient(scene->ambient);
	debug_camera(scene->camera);
	debug_light(scene->light);
	debug_objects(scene->objects);
	printf("\n====== END OF DEBUG INFORMATION ======\n\n");
}
