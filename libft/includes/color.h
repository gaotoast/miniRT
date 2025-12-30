/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:35:49 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 17:22:41 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	int	trans;
	int	red;
	int	green;
	int	blue;
}					t_color;

// color
t_color			*alloc_color(void);
int				color_create_trgb(int t, int r, int g, int b);
int				color_get_t(int color);
int				color_get_r(int color);
int				color_get_g(int color);
int				color_get_b(int color);

// struct color
t_color			*alloc_color(void);
t_color			*init_color(t_color *new, int color);
t_color			*new_color(t_color *new, int color);

#endif