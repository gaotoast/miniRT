/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:32:11 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/10 16:38:37 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	solve_quadratic(double a, double b, double discriminant)
{
	double	sqrt_disc;
	double	t;

	/* 実数解がある場合は最も手前の正の解を返す */
	sqrt_disc = sqrt(discriminant);
	t = (-b - sqrt_disc) / (2.0 * a);
	if (t > EPSILON)
		return (t);
	t = (-b + sqrt_disc) / (2.0 * a);
	if (t > EPSILON)
		return (t);
	return (-1.0);
}

int	intersect_sphere(t_vec3 origin, t_vec3 dir, t_sphere *sphere,
		double *distance, t_vec3 *normal)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	radius;
	double	t;
	t_vec3	point;

	if (!sphere || !distance || !normal)
		return (0);
	/* 二次方程式による標準的なレイと球の交差判定 */
	radius = sphere->diameter * 0.5;
	oc = vec3_sub(origin, sphere->center);
	a = vec3_dot(dir, dir);
	b = 2.0 * vec3_dot(oc, dir);
	c = vec3_dot(oc, oc) - radius * radius;
	discriminant = b * b - 4.0 * a * c;
	if (discriminant < 0.0)
		return (0);
	t = solve_quadratic(a, b, discriminant);
	if (t <= 0.0)
		return (0);
	point = vec3_add(origin, vec3_mul(dir, t));
	*distance = t;
	*normal = vec3_normalize(vec3_sub(point, sphere->center));
	if (vec3_dot(*normal, dir) > 0.0)
		*normal = vec3_mul(*normal, -1.0);
	return (1);
}
