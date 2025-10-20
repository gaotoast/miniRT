/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:47:59 by kinamura          #+#    #+#             */
/*   Updated: 2025/10/20 23:53:51 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

int		color_get_t(int t);
int		color_get_r(int r);
int		color_get_g(int g);
int		color_get_b(int b);

int	color_get_t(int t)
{
	return ((t >> 24) & 0xFF);
}

int	color_get_r(int r)
{
	return ((r >> 16) & 0xFF);
}

int	color_get_g(int g)
{
	return ((g >> 8) & 0xFF);
}

int	color_get_b(int b)
{
	return (b & 0xFF);
}
