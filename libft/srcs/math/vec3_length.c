/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:54:33 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 11:02:59 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

double	vec3_length(t_vec3 v)
{
	double	ret;

	ret = vec3_dot(v, v);
	ret = sqrt(ret);
	return (ret);
}
