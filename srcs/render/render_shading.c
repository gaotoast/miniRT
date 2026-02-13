/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:41:16 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/13 23:44:05 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	trgb_from_rgb(double r, double g, double b)
{
	int	red;
	int	green;
	int	blue;

	red = clamp_color(r);
	green = clamp_color(g);
	blue = clamp_color(b);
	return ((0 << 24) | (red << 16) | (green << 8) | blue);
}

int	get_background_color(t_scene *scene)
{
	double	r;
	double	g;
	double	b;

	if (!scene)
		return (0);
	r = scene->ambient.color.red * scene->ambient.ratio;
	g = scene->ambient.color.green * scene->ambient.ratio;
	b = scene->ambient.color.blue * scene->ambient.ratio;
	return (trgb_from_rgb(r, g, b));
}

static double	compute_channel(double obj_color, double ambient_color,
		double light_color, double ambient_ratio, double diffuse)
{
	double	ambient;
	double	light;

	ambient = ambient_ratio * ambient_color / 255.0;
	light = light_color / 255.0;
	return (obj_color * clamp01(ambient + light * diffuse));
}

int	shade_color(t_scene *scene, t_rgb object_color, double diffuse)
{
	double	r;
	double	g;
	double	b;

	if (!scene)
		return (0);
	if (diffuse < 0.0)
		diffuse = 0.0;
	r = compute_channel(object_color.red, scene->ambient.color.red,
			scene->light.color.red, scene->ambient.ratio, diffuse);
	g = compute_channel(object_color.green, scene->ambient.color.green,
			scene->light.color.green, scene->ambient.ratio, diffuse);
	b = compute_channel(object_color.blue, scene->ambient.color.blue,
			scene->light.color.blue, scene->ambient.ratio, diffuse);
	return (trgb_from_rgb(r, g, b));
}
