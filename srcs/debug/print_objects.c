/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:14:33 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:43:07 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	print_sphere(t_sphere *sphere)
{
	printf("Sphere:\n");
	print_vec3("  Center", sphere->center);
	printf("  Diameter: %.2f\n", sphere->diameter);
	print_color("  Color", sphere->color);
}

static void	print_plane(t_plane *plane)
{
	printf("Plane:\n");
	print_vec3("  Point", plane->point);
	print_vec3("  Normal", plane->normal);
	print_color("  Color", plane->color);
}

static void	print_cylinder(t_cylinder *cylinder)
{
	printf("Cylinder:\n");
	print_vec3("  Center", cylinder->center);
	print_vec3("  Axis", cylinder->axis);
	printf("  Diameter: %.2f\n", cylinder->diameter);
	printf("  Height: %.2f\n", cylinder->height);
	print_color("  Color", cylinder->color);
}

void	print_objects(t_obj*objects)
{
	t_obj	*current;
	int			count;

	current = objects;
	count = 0;
	printf("Objects List:\n");
	while (current)
	{
		printf("Object %d:\n", ++count);
		if (current->type == SPHERE)
			print_sphere((t_sphere *)current->obj_data);
		else if (current->type == PLANE)
			print_plane((t_plane *)current->obj_data);
		else if (current->type == CYLINDER)
			print_cylinder((t_cylinder *)current->obj_data);
		current = current->next;
	}
}
