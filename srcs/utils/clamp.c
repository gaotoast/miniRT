/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:49:01 by stakada           #+#    #+#             */
/*   Updated: 2026/02/11 22:35:22 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	clamp01(double value)
{
	if (value < 0.0)
		return (0.0);
	if (value > 1.0)
		return (1.0);
	return (value);
}

int	clamp_color(double value)
{
	if (value < 0.0)
		return (0);
	if (value > 255.0)
		return (255);
	return ((int)(value + 0.5));
}
