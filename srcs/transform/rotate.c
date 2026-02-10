/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:19:29 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:20:18 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	rotate_camera(t_camera *camera, t_vec3 axis, double angle)
{
	camera->direction = vec3_normalize(vec3_rotate(camera->direction, axis,
				angle));
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
