/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 00:47:58 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/11 22:44:57 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	set_world_up(t_vec3 forward, t_vec3 *world_up)
{
	if (fabs(forward.y) > 0.999)
		*world_up = vec3(0.0, 0.0, 1.0);
	else
		*world_up = vec3(0.0, 1.0, 0.0);
}

static void	init_camera_frame(t_camera camera, t_camera_frame *frame)
{
	t_vec3	world_up;
	double	fov_rad;
	double	aspect_ratio;

	frame->origin = camera.position;
	frame->forward = camera.direction;
	set_world_up(frame->forward, &world_up);
	frame->right = vec3_normalize(vec3_cross(frame->forward, world_up));
	frame->up = vec3_normalize(vec3_cross(frame->right, frame->forward));
	fov_rad = camera.fov_deg * PI / 180.0;
	frame->half_width = tan(fov_rad * 0.5);
	aspect_ratio = (double)WIN_HEIGHT / (double)WIN_WIDTH;
	frame->half_height = frame->half_width * aspect_ratio;
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

// TODO: delete debug statement (print_scene)
void	render_scene(t_ctx *ctx)
{
	t_camera_frame	frame;
	int				x;
	int				y;
	t_ray			ray;
	int				color;

	if (!ctx || !ctx->scene || !ctx->img)
		return ;
	print_scene(ctx->scene);
	init_camera_frame(ctx->scene->camera, &frame);
	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray.origin = frame.origin;
			ray.direction = get_ray_direction(&frame, x, y);
			color = trace_ray(ctx->scene, ray);
			my_mlx_pixel_put(ctx->img, x, y, color);
			x++;
		}
		y++;
	}
}
