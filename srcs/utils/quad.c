/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 22:35:11 by stakada           #+#    #+#             */
/*   Updated: 2026/02/11 22:35:25 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	quad_roots(t_quad *q, double *t0, double *t1)
{
	double	sqrt_disc;
	double	denom;

	sqrt_disc = sqrt(q->disc);
	denom = 2.0 * q->a;
	*t0 = (-q->b - sqrt_disc) / denom;
	*t1 = (-q->b + sqrt_disc) / denom;
}
