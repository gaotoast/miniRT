/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:20:27 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:20:38 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	adjust_fov(t_camera *camera, double delta)
{
	camera->fov_deg += delta;
	if (camera->fov_deg < 1.0)
		camera->fov_deg = 1.0;
	if (camera->fov_deg > 179.0)
		camera->fov_deg = 179.0;
}

void	adjust_brightness(t_light *light, double delta)
{
	light->brightness += delta;
	if (light->brightness < 0.0)
		light->brightness = 0.0;
	if (light->brightness > 1.0)
		light->brightness = 1.0;
}
