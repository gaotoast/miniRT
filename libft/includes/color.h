/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:35:49 by kinamura          #+#    #+#             */
/*   Updated: 2026/02/13 21:36:35 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}		t_rgb;

typedef struct s_trgb
{
	int	trans;
	int	red;
	int	green;
	int	blue;
}		t_trgb;

// color
int		color_create_trgb(int t, int r, int g, int b);
int		color_get_t(int color);
int		color_get_r(int color);
int		color_get_g(int color);
int		color_get_b(int color);

// struct color
t_trgb	*alloc_color(void);
t_trgb	*init_color(t_trgb *new, int color);
t_trgb	*new_color(t_trgb *new, int color);

#endif