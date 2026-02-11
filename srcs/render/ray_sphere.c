/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:11 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/11 20:30:53 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	get_quadratic_coeffs(t_ray ray, t_sphere *sp, double *b, double *c)
{
	t_vec3	oc;
	double	radius;

	oc = vec3_sub(ray.origin, sp->center);
	radius = sp->diameter * 0.5;
	*b = 2.0 * vec3_dot(oc, ray.direction);
	*c = vec3_dot(oc, oc) - radius * radius;
}

static double	nearest_t(double a, double b, double disc)
{
	double	sqrt_disc;
	double	t;

	sqrt_disc = sqrt(disc);
	t = (-b - sqrt_disc) / (2.0 * a);
	if (t > EPSILON)
		return (t);
	t = (-b + sqrt_disc) / (2.0 * a);
	if (t > EPSILON)
		return (t);
	return (-1.0);
}

static double	find_intersection_t(t_ray ray, t_sphere *sp)
{
	double	a;
	double	b;
	double	c;
	double	disc;

	a = vec3_dot(ray.direction, ray.direction);
	get_quadratic_coeffs(ray, sp, &b, &c);
	disc = b * b - 4.0 * a * c;
	if (disc < 0.0)
		return (-1.0);
	return (nearest_t(a, b, disc));
}

static void	calculate_hit_details(t_ray ray, t_sphere *sp, t_hit *hit, double t)
{
	t_vec3	point;
	t_vec3	normal;

	hit->distance = t;
	point = vec3_add(ray.origin, vec3_mul(ray.direction, t));
	normal = vec3_normalize(vec3_sub(point, sp->center));
	hit->normal = front_normal(normal, ray.direction);
}

int	calculate_sphere_hit(t_ray ray, t_sphere *sp, t_hit *hit)
{
	double	t;

	if (!sp || !hit)
		return (0);
	t = find_intersection_t(ray, sp);
	if (t <= EPSILON)
		return (0);
	calculate_hit_details(ray, sp, hit, t);
	return (1);
}
