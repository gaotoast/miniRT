/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:49:14 by kinamura          #+#    #+#             */
/*   Updated: 2025/12/29 16:22:19 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include <math.h>
# include <stdlib.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

// math
int					ft_abs(int i);
int					ft_max(int a, int b);
int					ft_min(int a, int b);

// vec3
t_vec3				vec3(double x, double y, double z);
t_vec3				*vec3_alloc(void);
t_vec3				*vec3_init(t_vec3 *new, double x, double y, double z);

// vec
t_vec3				vec3_add(t_vec3 a, t_vec3 b);
t_vec3				vec3_sub(t_vec3 a, t_vec3 b);
t_vec3				vec3_mul(t_vec3 v, double t);
double				vec3_dot(t_vec3 a, t_vec3 b);
double				vec3_length(t_vec3 v);
t_vec3				vec3_normalize(t_vec3 v);

#endif