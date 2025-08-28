/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 22:11:37 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 22:15:04 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_vec3(const char *prefix, t_vec3 vec)
{
	printf("%s: (%.2f, %.2f, %.2f)\n", prefix, vec.x, vec.y, vec.z);
}

void	print_color(const char *prefix, t_color color)
{
	printf("%s: (%.2f, %.2f, %.2f)\n", prefix, color.r, color.g, color.b);
}
