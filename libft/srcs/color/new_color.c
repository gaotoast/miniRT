/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:40:18 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 17:23:26 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color	*new_color(t_color *new, int color)
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
