/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:11:06 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 11:11:09 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

t_vec3	vec3_normalize(t_vec3 v)
{
	double	length;

	length = vec3_length(v);
	if (length == 0.0)
		return (vec3(0.0, 0.0, 0.0));
	return (vec3_mul(v, 1.0 / length));
}
