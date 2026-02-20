/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:11 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/20 20:17:26 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	find_sphere_hit_t(t_ray ray, t_sp_ctx *c)
{
	t_quad	q;
	t_vec3	oc;
	double	roots[2];

	oc = vec3_sub(ray.origin, c->sp->center);
	q.a = vec3_dot(ray.direction, ray.direction);
	q.b = 2.0 * vec3_dot(oc, ray.direction);
	q.c = vec3_dot(oc, oc) - c->radius * c->radius;
	q.disc = q.b * q.b - 4.0 * q.a * q.c;
	if (q.disc < 0.0)
		return (-1.0);
	quad_roots(&q, &roots[0], &roots[1]);
	if (roots[0] > EPSILON)
		return (roots[0]);
	if (roots[1] > EPSILON)
		return (roots[1]);
	return (-1.0);
}

int	calculate_sphere_hit(t_ray ray, t_sphere *sp, t_hit *hit)
{
	t_sp_ctx	c;
	double		t;
	t_vec3		point;
	t_vec3		normal;

	if (!sp || !hit)
		return (0);
	c.sp = sp;
	c.radius = sp->diameter * 0.5;
	t = find_sphere_hit_t(ray, &c);
	if (t <= EPSILON)
		return (0);
	hit->distance = t;
	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	normal = vec3_normalize(vec3_sub(point, c.sp->center));
	hit->normal = front_normal(normal, ray.direction);
	return (1);
}
