/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:47:48 by kinamura          #+#    #+#             */
/*   Updated: 2025/10/20 23:56:57 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	*alloc_color(void);
t_color	*new_color(t_color *clr, int color);
int		color_create_trgb(int t, int r, int g, int b);
int		color_lerp(int start, int end, double ratio);

t_color	*alloc_color(void)
{
	t_color	*new;

	new = (t_color *)ft_calloc(1, sizeof(t_color));
	if (!new)
		return (NULL);
	new->trans = 0;
	new->red = 0;
	new->green = 0;
	new->blue = 0;
	new->color = 0;
	return (new);
}

t_color	*new_color(t_color *clr, int color)
{
	if (!clr)
		return (NULL);
	clr->trans = color_get_t(color);
	clr->red = color_get_r(color);
	clr->green = color_get_g(color);
	clr->blue = color_get_b(color);
	clr->color = color;
	return (clr);
}

// color作成
int	color_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// グラデーション補完
int	color_lerp(int start, int end, double ratio)
{
	t_color	color1;
	t_color	color2;
	int		color;

	color1.trans = color_get_t(start);
	color1.red = color_get_r(start);
	color1.green = color_get_g(start);
	color1.blue = color_get_b(start);
	color2.trans = color_get_t(end);
	color2.red = color_get_r(end);
	color2.green = color_get_g(end);
	color2.blue = color_get_b(end);
	color = color_create_trgb(
			(color1.trans + (color2.trans - color1.trans)) * ratio,
			(color1.red + (color2.red - color1.red)) * ratio,
			(color1.green + (color2.green - color1.green)) * ratio,
			(color1.blue + (color2.blue - color1.blue)) * ratio);
	return (color);
}
