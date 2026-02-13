/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:41:16 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/14 00:06:42 by stakada          ###   ########.fr       */
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

int	background_color(t_ambient ambient)
{
	double	r;
	double	g;
	double	b;

	r = ambient.color.red * ambient.ratio;
	g = ambient.color.green * ambient.ratio;
	b = ambient.color.blue * ambient.ratio;
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

int	shade_color(t_ambient ambient, t_light light, t_rgb obj_color,
		double diffuse)
{
	double	r;
	double	g;
	double	b;

	if (diffuse < 0.0)
		diffuse = 0.0;
	r = compute_channel(obj_color.red, ambient.color.red, light.color.red,
			ambient.ratio, diffuse);
	g = compute_channel(obj_color.green, ambient.color.green, light.color.green,
			ambient.ratio, diffuse);
	b = compute_channel(obj_color.blue, ambient.color.blue, light.color.blue,
			ambient.ratio, diffuse);
	return (trgb_from_rgb(r, g, b));
}
