/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_shading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:41:16 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/20 20:07:48 by stakada          ###   ########.fr       */
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

static double	compute_channel(t_color_channels params, double ambient_ratio,
		double diffuse)
{
	double	ambient;
	double	light;

	ambient = ambient_ratio * params.ambient_color / 255.0;
	light = params.light_color / 255.0;
	return (params.obj_color * clamp01(ambient + light * diffuse));
}

int	shade_color(t_ambient ambient, t_light light, t_rgb obj_color,
		double diffuse)
{
	double				r;
	double				g;
	double				b;
	t_color_channels	params;

	if (diffuse < 0.0)
		diffuse = 0.0;
	params.obj_color = obj_color.red;
	params.ambient_color = ambient.color.red;
	params.light_color = light.color.red;
	r = compute_channel(params, ambient.ratio, diffuse);
	params.obj_color = obj_color.green;
	params.ambient_color = ambient.color.green;
	params.light_color = light.color.green;
	g = compute_channel(params, ambient.ratio, diffuse);
	params.obj_color = obj_color.blue;
	params.ambient_color = ambient.color.blue;
	params.light_color = light.color.blue;
	b = compute_channel(params, ambient.ratio, diffuse);
	return (trgb_from_rgb(r, g, b));
}
