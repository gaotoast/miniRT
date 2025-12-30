/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:36:31 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 16:38:32 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (new);
}
