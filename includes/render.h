/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:15:08 by stakada           #+#    #+#             */
/*   Updated: 2026/02/11 21:20:07 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_camera_frame
{
	t_vec3	origin;
	t_vec3	forward;
	t_vec3	right;
	t_vec3	up;
	double	half_width;
	double	half_height;
}			t_camera_frame;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}			t_ray;

typedef struct s_hit
{
	t_obj	*object;
	t_vec3	point;
	t_vec3	normal;
	t_color	color;
	double	distance;
}			t_hit;

// render
void		render_scene(t_ctx *ctx);
int			trace_ray(t_scene *scene, t_ray ray);
int			find_nearest_hit(t_scene *scene, t_ray ray, t_hit *nearest_hit);

// ray
int			calculate_sphere_hit(t_ray ray, t_sphere *sp, t_hit *hit);
int			calculate_plane_hit(t_ray ray, t_plane *pl, t_hit *hit);
int			calculate_cylinder_hit(t_ray ray, t_cylinder *cy, t_hit *hit);

// shading
int			get_background_color(t_scene *scene);
int			shade_color(t_scene *scene, t_color object_color, double diffuse);

#endif