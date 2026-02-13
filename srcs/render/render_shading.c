/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:41:16 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/13 21:38:06 by stakada          ###   ########.fr       */
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

static double	channel_intensity(double ambient, double light, double diffuse)
{
	return (clamp01(ambient + light * diffuse));
}

int	shade_color(t_scene *scene, t_rgb object_color, double diffuse)
{
	double	ambient_r;
	double	ambient_g;
	double	ambient_b;
	double	light_r;
	double	light_g;
	double	light_b;

	if (!scene)
		return (0);
	if (diffuse < 0.0)
		diffuse = 0.0;
	ambient_r = scene->ambient.ratio * scene->ambient.color.red / 255.0;
	ambient_g = scene->ambient.ratio * scene->ambient.color.green / 255.0;
	ambient_b = scene->ambient.ratio * scene->ambient.color.blue / 255.0;
	light_r = scene->light.color.red / 255.0;
	light_g = scene->light.color.green / 255.0;
	light_b = scene->light.color.blue / 255.0;
	return (trgb_from_rgb(object_color.red * channel_intensity(ambient_r,
				light_r, diffuse), object_color.green
			* channel_intensity(ambient_g, light_g, diffuse), object_color.blue
			* channel_intensity(ambient_b, light_b, diffuse)));
}
