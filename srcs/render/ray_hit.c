/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 18:44:45 by stakada           #+#    #+#             */
/*   Updated: 2026/02/11 20:36:00 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	get_object_color(t_obj *object)
{
	t_color	color;

	if (object->type == SPHERE)
		return (((t_sphere *)object->obj_data)->color);
	if (object->type == PLANE)
		return (((t_plane *)object->obj_data)->color);
	if (object->type == CYLINDER)
		return (((t_cylinder *)object->obj_data)->color);
	color.red = 0.0;
	color.green = 0.0;
	color.blue = 0.0;
	return (color);
}

static void	update_nearest_hit(t_obj *object, t_ray ray, t_hit *nearest_hit)
{
	t_hit	current_hit;
	int		is_hit;

	if (object->type == SPHERE)
		is_hit = calculate_sphere_hit(ray, (t_sphere *)object->obj_data,
				&current_hit);
	else if (object->type == PLANE)
		is_hit = calculate_plane_hit(ray, (t_plane *)object->obj_data,
				&current_hit);
	else if (object->type == CYLINDER)
		is_hit = calculate_cylinder_hit(ray, (t_cylinder *)object->obj_data,
				&current_hit);
	else
		is_hit = 0;
	if (is_hit && current_hit.distance < nearest_hit->distance)
	{
		nearest_hit->object = object;
		nearest_hit->distance = current_hit.distance;
		nearest_hit->normal = current_hit.normal;
	}
}

int	find_nearest_hit(t_scene *scene, t_ray ray, t_hit *nearest_hit)
{
	t_obj	*object;

	if (!scene || !nearest_hit)
		return (0);
	nearest_hit->object = NULL;
	nearest_hit->distance = DBL_MAX;
	nearest_hit->normal = vec3(0.0, 0.0, 0.0);
	object = scene->objects;
	while (object)
	{
		update_nearest_hit(object, ray, nearest_hit);
		object = object->next;
	}
	if (!nearest_hit->object)
		return (0);
	nearest_hit->point = vec3_add(ray.origin, vec3_mul(ray.direction,
				nearest_hit->distance));
	nearest_hit->color = get_object_color(nearest_hit->object);
	return (1);
}
