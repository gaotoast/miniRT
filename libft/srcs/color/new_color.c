/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:40:18 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/13 21:35:56 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trgb	*new_color(t_trgb *new, int color)
{
	if (!new)
	{
		new = alloc_color();
		if (!new)
			return (NULL);
	}
	init_color(new, color);
	return (new);
}
