/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:20:58 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 17:23:09 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	*init_color(t_color *new, int color)
{
	if (!new)
		return (NULL);
	new->trans = color_get_t(color);
	new->red = color_get_r(color);
	new->green = color_get_g(color);
	new->blue = color_get_b(color);
	return (new);
}
