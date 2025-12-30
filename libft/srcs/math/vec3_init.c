/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:09:22 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 11:13:24 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec3	*vec3_init(t_vec3 *new, double x, double y, double z)
{
	if (!new)
	{
		new = vec3_alloc();
		if (!new)
			return (NULL);
	}
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
