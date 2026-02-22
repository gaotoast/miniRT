/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:25 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/20 20:16:14 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	update_side_hit(t_ray ray, t_cy_ctx *c, t_hit *hit, double t)
{
	t_vec3	point;
	double	dot;
	t_vec3	normal;

	if (t <= EPSILON || t >= hit->distance)
		return ;
	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	dot = vec3_dot(vec3_sub(point, c->cy->center), c->cy->axis);
	if (dot < -c->half_h || dot > c->half_h)
		return ;
	normal = vec3_sub(vec3_sub(point, c->cy->center), vec3_mul(c->cy->axis,
				dot));
	normal = vec3_normalize(normal);
	hit->distance = t;
	hit->normal = front_normal(normal, ray.direction);
}

static void	find_cylinder_side_hit(t_ray ray, t_cy_ctx *c, t_hit *hit)
{
	t_vec3	oc;
	t_quad	q;
	double	roots[2];

	oc = vec3_sub(ray.origin, c->cy->center);
	q.a = vec3_dot(ray.direction, ray.direction) - pow(vec3_dot(ray.direction,
				c->cy->axis), 2);
	q.b = 2.0 * (vec3_dot(ray.direction, oc) - vec3_dot(ray.direction,
				c->cy->axis) * vec3_dot(oc, c->cy->axis));
	q.c = vec3_dot(oc, oc) - pow(vec3_dot(oc, c->cy->axis), 2) - c->radius
		* c->radius;
	if (fabs(q.a) <= EPSILON)
		return ;
	q.disc = q.b * q.b - 4.0 * q.a * q.c;
	if (q.disc < 0.0)
		return ;
	quad_roots(&q, &roots[0], &roots[1]);
	if (roots[0] > EPSILON)
		update_side_hit(ray, c, hit, roots[0]);
	if (roots[1] > EPSILON)
		update_side_hit(ray, c, hit, roots[1]);
}

static void	find_cylinder_cap_hit(t_ray ray, t_cap_ctx cap, t_hit *hit)
{
	double	t;
	t_vec3	point;

	t = find_plane_hit_t(ray, cap.center, cap.normal);
	if (t <= EPSILON || t >= hit->distance)
		return ;
	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	if (vec3_dot(vec3_sub(point, cap.center), vec3_sub(point, cap.center))
		> cap.radius * cap.radius)
		return ;
	hit->distance = t;
	hit->normal = front_normal(cap.normal, ray.direction);
}

int	calculate_cylinder_hit(t_ray ray, t_cylinder *cy, t_hit *hit)
{
	t_cy_ctx	c;
	t_cap_ctx	cap;

	if (!cy || !hit)
		return (0);
	c.cy = cy;
	c.radius = cy->diameter * 0.5;
	c.half_h = cy->height * 0.5;
	hit->distance = DBL_MAX;
	find_cylinder_side_hit(ray, &c, hit);
	cap.center = vec3_add(cy->center, vec3_mul(cy->axis, c.half_h));
	cap.normal = cy->axis;
	cap.radius = c.radius;
	find_cylinder_cap_hit(ray, cap, hit);
	cap.center = vec3_add(cy->center, vec3_mul(cy->axis, -(c.half_h)));
	cap.normal = vec3_mul(cy->axis, -1.0);
	find_cylinder_cap_hit(ray, cap, hit);
	if (hit->distance == DBL_MAX)
		return (0);
	return (1);
}
