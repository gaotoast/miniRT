/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:46:35 by stakada           #+#    #+#             */
/*   Updated: 2026/02/14 00:07:15 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	is_in_shadow(t_scene *scene, t_hit *hit, t_vec3 light_dir,
		double light_distance)
{
	t_ray	shadow_ray;
	t_hit	shadow_hit;

	if (!scene || !hit)
		return (0);
	shadow_ray.origin = vec3_add(hit->point, vec3_mul(hit->normal, EPSILON));
	shadow_ray.direction = light_dir;
	if (find_nearest_hit(scene, shadow_ray, &shadow_hit)
		&& shadow_hit.distance < light_distance)
		return (1);
	return (0);
}

static double	calculate_diffuse_lighting(t_hit *hit, t_light light,
		t_scene *scene)
{
	t_vec3	light_dir;
	double	light_distance;
	double	dot;

	if (!scene || !hit || light.brightness <= 0.0)
		return (0.0);
	light_dir = vec3_sub(light.position, hit->point);
	light_distance = vec3_length(light_dir);
	if (light_distance <= EPSILON)
		return (0.0);
	light_dir = vec3_normalize(light_dir);
	dot = vec3_dot(hit->normal, light_dir);
	if (dot <= 0.0)
		return (0.0);
	if (is_in_shadow(scene, hit, light_dir, light_distance))
		return (0.0);
	return (dot * light.brightness);
}

int	trace_ray(t_scene *scene, t_ray ray)
{
	t_hit	hit;
	double	diffuse;

	if (!scene)
		return (0);
	if (!find_nearest_hit(scene, ray, &hit))
		return (background_color(scene->ambient));
	diffuse = calculate_diffuse_lighting(&hit, scene->light, scene);
	return (shade_color(scene->ambient, scene->light, hit.color, diffuse));
}
