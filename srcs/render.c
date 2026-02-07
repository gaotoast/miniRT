/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:47:58 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/30 14:35:58 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_world_up(t_vec3 forward, t_vec3 *world_up)
{
	/* カメラの前方向と平行にならないよう基準の上方向を選ぶ */
	if (fabs(forward.y) > 0.999)
		*world_up = vec3(0.0, 0.0, 1.0);
	else
		*world_up = vec3(0.0, 1.0, 0.0);
}

static void	init_camera_frame(t_camera camera, t_camera_frame *frame)
{
	t_vec3	world_up;
	double	fov_rad;
	double	aspect;

	frame->origin = camera.position;
	frame->forward = vec3_normalize(camera.direction);
	set_world_up(frame->forward, &world_up);
	frame->right = vec3_normalize(vec3_cross(frame->forward, world_up));
	frame->up = vec3_normalize(vec3_cross(frame->right, frame->forward));
	fov_rad = camera.fov * PI / 180.0;
	frame->half_width = tan(fov_rad * 0.5);
	aspect = (double)WIN_HEIGHT / (double)WIN_WIDTH;
	frame->half_height = frame->half_width * aspect;
}

static t_vec3	get_ray_direction(t_camera_frame *frame, int x, int y)
{
	double	u;
	double	v;
	t_vec3	dir;

	u = ((double)x + 0.5) / (double)WIN_WIDTH;
	v = ((double)y + 0.5) / (double)WIN_HEIGHT;
	u = 2.0 * u - 1.0;
	v = 1.0 - 2.0 * v;
	dir = frame->forward;
	dir = vec3_add(dir, vec3_mul(frame->right, u * frame->half_width));
	dir = vec3_add(dir, vec3_mul(frame->up, v * frame->half_height));
	return (vec3_normalize(dir));
}

static t_color	get_object_color(t_object *object)
{
	t_color	color;

	/* 一般化されたオブジェクトポインタから対応する色を取得 */
	if (object->type == SPHERE)
		return (((t_sphere *)object->obj_data)->color);
	if (object->type == PLANE)
		return (((t_plane *)object->obj_data)->color);
	if (object->type == CYLINDER)
		return (((t_cylinder *)object->obj_data)->color);
	color.red = 0.0;
	color.green = 0.0;
	color.blue = 0.0;
	return (color);
}

static int	intersect_object(t_object *object, t_vec3 origin, t_vec3 dir,
			double *distance, t_vec3 *normal)
{
	/* オブジェクト種別に応じて適切な交差判定関数へ振り分け */
	if (object->type == SPHERE)
		return (intersect_sphere(origin, dir, (t_sphere *)object->obj_data, distance, normal));
	if (object->type == PLANE)
		return (intersect_plane(origin, dir, (t_plane *)object->obj_data, distance, normal));
	if (object->type == CYLINDER)
		return (intersect_cylinder(origin, dir, (t_cylinder *)object->obj_data, distance, normal));
	return (0);
}

static int	find_closest_hit(t_ctx *ctx, t_vec3 origin, t_vec3 dir, t_hit *hit)
{
	t_object	*object;
	double		distance;
	double		best_distance;
	t_vec3		normal;
	t_vec3		best_normal;
	t_object	*best_object;

	if (!ctx || !ctx->scene || !hit)
		return (0);
	object = ctx->scene->objects;
	best_distance = DBL_MAX;
	best_object = NULL;
	best_normal = vec3(0.0, 0.0, 0.0);
	while (object)
	{
		/* レイ上で最も手前側の交差点のみを採用 */
		if (intersect_object(object, origin, dir, &distance, &normal)
			&& distance < best_distance)
		{
			best_distance = distance;
			best_object = object;
			best_normal = normal;
		}
		object = object->next;
	}
	if (!best_object)
		return (0);
	hit->object = best_object;
	hit->distance = best_distance;
	hit->point = vec3_add(origin, vec3_mul(dir, best_distance));
	hit->normal = vec3_normalize(best_normal);
	hit->color = get_object_color(best_object);
	return (1);
}

static int	is_black_light(t_color color)
{
	return (color.red <= 0 && color.green <= 0 && color.blue <= 0);
}

static int	is_in_shadow(t_ctx *ctx, t_hit *hit,
			t_vec3 light_dir, double light_distance)
{
	t_object	*object;
	t_vec3		origin;
	double		distance;
	t_vec3		normal;
	double		max_distance;

	if (!ctx || !ctx->scene || !hit)
		return (0);
	max_distance = light_distance - EPSILON;
	if (max_distance <= 0.0)
		return (0);
	origin = vec3_add(hit->point, vec3_mul(hit->normal, EPSILON));
	object = ctx->scene->objects;
	while (object)
	{
		/* 光源に到達するまでに遮るオブジェクトがあれば影になる */
		if (object != hit->object
			&& intersect_object(object, origin, light_dir, &distance, &normal)
			&& distance < max_distance)
			return (1);
		object = object->next;
	}
	return (0);
}

static int	trace_ray(t_ctx *ctx, t_vec3 origin, t_vec3 dir)
{
	t_hit		hit;
	t_vec3		light_vector;
	t_vec3		light_dir;
	double		light_distance;
	double		diffuse;

	if (!ctx || !ctx->scene)
		return (0);
	if (!find_closest_hit(ctx, origin, dir, &hit))
		return (get_background_color(ctx->scene));
	light_vector = vec3_sub(ctx->scene->light.position, hit.point);
	light_distance = vec3_length(light_vector);
	if (light_distance <= EPSILON)
		return (shade_color(ctx->scene, hit.color, 0.0));
	light_dir = vec3_mul(light_vector, 1.0 / light_distance);
	diffuse = vec3_dot(hit.normal, light_dir);
	if (diffuse <= 0.0 || ctx->scene->light.brightness <= 0.0
		|| is_black_light(ctx->scene->light.color))
		diffuse = 0.0;
	else
	{
		if (is_in_shadow(ctx, &hit, light_dir, light_distance))
			diffuse = 0.0;
		else
			diffuse *= ctx->scene->light.brightness;
	}
	return (shade_color(ctx->scene, hit.color, diffuse));
}

static void	render_row(t_ctx *ctx, t_camera_frame *frame, int y)
{
	int		x;
	t_vec3	dir;
	int		color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		dir = get_ray_direction(frame, x, y);
		color = trace_ray(ctx, frame->origin, dir);
		my_mlx_pixel_put(ctx->img, x, y, color);
		x++;
	}
}

void	render_scene(t_ctx *ctx)
{
	t_camera_frame	frame;
	int				y;

	if (!ctx || !ctx->scene || !ctx->img)
		return ;
	init_camera_frame(ctx->scene->camera, &frame);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		render_row(ctx, &frame, y);
		y++;
	}
}
