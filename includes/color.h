/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 23:48:04 by kinamura          #+#    #+#             */
/*   Updated: 2025/10/20 23:56:14 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

#include "libft.h"

typedef struct s_color{
	int	color;
	int	trans;
	int	red;
	int	green;
	int	blue;
}				t_color;

// get_color.c
int		color_get_t(int t);
int		color_get_r(int r);
int		color_get_g(int g);
int		color_get_b(int b);

// ft_color.c
t_color	*alloc_color(void);
t_color	*new_color(t_color *clr, int color);
int		color_create_trgb(int t, int r, int g, int b);
int		color_lerp(int start, int end, double ratio);

# endif