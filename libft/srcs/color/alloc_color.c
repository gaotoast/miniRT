/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:36:31 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/13 21:30:11 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trgb	*alloc_color(void)
{
	t_trgb	*new;

	new = (t_trgb *)ft_calloc(1, sizeof(t_trgb));
	if (!new)
		return (NULL);
	new->trans = 0;
	new->red = 0;
	new->green = 0;
	new->blue = 0;
	return (new);
}
