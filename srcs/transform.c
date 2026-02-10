/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 20:00:00 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/10 14:14:32 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	translate_camera(t_camera *camera, t_vec3 delta)
{
	camera->position = vec3_add(camera->position, delta);
}

void	rotate_camera(t_camera *camera, t_vec3 axis, double angle)
{
	camera->direction = vec3_normalize(vec3_rotate(camera->direction, axis,
				angle));
}

void	adjust_fov(t_camera *camera, double delta)
{
	camera->fov += delta;
	if (camera->fov < 1.0)
		camera->fov = 1.0;
	if (camera->fov > 179.0)
		camera->fov = 179.0;
}

void	translate_light(t_light *light, t_vec3 delta)
{
	light->position = vec3_add(light->position, delta);
}

void	adjust_brightness(t_light *light, double delta)
{
	light->brightness += delta;
	if (light->brightness < 0.0)
		light->brightness = 0.0;
	if (light->brightness > 1.0)
		light->brightness = 1.0;
}

static void	translate_object_by_type(t_object *obj, t_vec3 delta)
{
	if (obj->type == SPHERE)
		((t_sphere *)obj->obj_data)->center = vec3_add(((t_sphere *)obj->obj_data)->center,
				delta);
	else if (obj->type == PLANE)
		((t_plane *)obj->obj_data)->point = vec3_add(((t_plane *)obj->obj_data)->point,
				delta);
	else if (obj->type == CYLINDER)
		((t_cylinder *)obj->obj_data)->center = vec3_add(((t_cylinder *)obj->obj_data)->center,
				delta);
}

void	translate_object(t_object *objects, int index, t_vec3 delta)
{
	t_object	*obj;
	int			i;

	obj = objects;
	i = 0;
	while (obj && i < index)
	{
		obj = obj->next;
		i++;
	}
	if (obj)
		translate_object_by_type(obj, delta);
}

static void	rotate_object_by_type(t_object *obj, t_vec3 axis, double angle)
{
	t_plane		*plane;
	t_cylinder	*cylinder;

	if (obj->type == PLANE)
	{
		plane = (t_plane *)obj->obj_data;
		plane->normal = vec3_normalize(vec3_rotate(plane->normal, axis, angle));
	}
	else if (obj->type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->obj_data;
		cylinder->axis = vec3_normalize(vec3_rotate(cylinder->axis, axis,
					angle));
	}
}

void	rotate_object(t_object *objects, int index, t_vec3 axis, double angle)
{
	t_object	*obj;
	int			i;

	obj = objects;
	i = 0;
	while (obj && i < index)
	{
		obj = obj->next;
		i++;
	}
	if (obj)
		rotate_object_by_type(obj, axis, angle);
}

static void	resize_object_by_type(t_object *obj, double delta, int height_mode)
{
	t_sphere	*sphere;
	t_cylinder	*cylinder;

	if (obj->type == SPHERE)
	{
		sphere = (t_sphere *)obj->obj_data;
		sphere->diameter += delta;
		if (sphere->diameter < 0.1)
			sphere->diameter = 0.1;
	}
	else if (obj->type == CYLINDER)
	{
		cylinder = (t_cylinder *)obj->obj_data;
		if (height_mode)
		{
			cylinder->height += delta;
			if (cylinder->height < 0.1)
				cylinder->height = 0.1;
		}
		else
		{
			cylinder->diameter += delta;
			if (cylinder->diameter < 0.1)
				cylinder->diameter = 0.1;
		}
	}
}

void	resize_object(t_object *objects, int index, double delta, int h_mode)
{
	t_object	*obj;
	int			i;

	obj = objects;
	i = 0;
	while (obj && i < index)
	{
		obj = obj->next;
		i++;
	}
	if (obj)
		resize_object_by_type(obj, delta, h_mode);
}

int	count_objects(t_object *objects)
{
	int			count;
	t_object	*obj;

	count = 0;
	obj = objects;
	while (obj)
	{
		count++;
		obj = obj->next;
	}
	return (count);
}
