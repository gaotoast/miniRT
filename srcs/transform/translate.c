/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:18:14 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:22:08 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	translate_camera(t_camera *camera, t_vec3 delta)
{
	camera->position = vec3_add(camera->position, delta);
}

void	translate_light(t_light *light, t_vec3 delta)
{
	light->position = vec3_add(light->position, delta);
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
