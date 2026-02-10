/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:15:34 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 15:38:10 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	print_ambient(t_ambient ambient)
{
	printf("Ambient Light:\n");
	printf("  Ratio: %.2f\n", ambient.ratio);
	print_color("  Color", ambient.color);
}

static void	print_camera(t_camera camera)
{
	printf("Camera:\n");
	print_vec3("  Position", camera.position);
	print_vec3("  Direction", camera.direction);
	printf("  FOV: %.2f\n", camera.fov_deg);
}

static void	print_light(t_light light)
{
	printf("Light:\n");
	print_vec3("  Position", light.position);
	printf("  Brightness: %.2f\n", light.brightness);
	print_color("  Color", light.color);
}

void	print_scene(t_scene *scene)
{
	if (!scene)
	{
		printf("Error: Scene is NULL\n");
		return ;
	}
	printf("\n===== Scene Information =====\n\n");
	print_ambient(scene->ambient);
	printf("\n");
	print_camera(scene->camera);
	printf("\n");
	print_light(scene->light);
	printf("\n");
	print_objects(scene->objects);
	printf("\n==========================\n\n");
}
