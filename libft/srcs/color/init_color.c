/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:20:58 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/13 21:35:48 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trgb	*init_color(t_trgb *new, int color)
{
	if (!new)
		return (NULL);
	new->trans = color_get_t(color);
	new->red = color_get_r(color);
	new->green = color_get_g(color);
	new->blue = color_get_b(color);
	return (new);
}
