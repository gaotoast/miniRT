/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:19:58 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:20:08 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
