/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:44:50 by stakada           #+#    #+#             */
/*   Updated: 2026/02/23 10:48:44 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define WIN_WIDTH 1080
# define WIN_HEIGHT 800
# define EXT ".rt"
# define PROGRAM "miniRT"
# define EXECUTION "./miniRT"
# define EPSILON 1e-6
# define NORM_EPSILON 1e-3
# define DBL_MAX __DBL_MAX__

# if defined(__APPLE__)
#  define ESC_KEY 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_Q 12
#  define KEY_E 14
#  define KEY_1 18
#  define KEY_2 19
#  define KEY_3 20
#  define KEY_TAB 48
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_PLUS 24
#  define KEY_MINUS 27
#  define KEY_P 35
#  define KEY_M 46
#  define KEY_H 4
#  define KEY_J 38
# else
#  include <X11/keysym.h>
#  define ESC_KEY XK_Escape
#  define KEY_W XK_w
#  define KEY_A XK_a
#  define KEY_S XK_s
#  define KEY_D XK_d
#  define KEY_Q XK_q
#  define KEY_E XK_e
#  define KEY_1 XK_1
#  define KEY_2 XK_2
#  define KEY_3 XK_3
#  define KEY_TAB XK_Tab
#  define KEY_UP XK_Up
#  define KEY_DOWN XK_Down
#  define KEY_LEFT XK_Left
#  define KEY_RIGHT XK_Right
#  define KEY_PLUS XK_plus
#  define KEY_MINUS XK_minus
#  define KEY_P XK_p
#  define KEY_M XK_m
#  define KEY_H XK_h
#  define KEY_J XK_j
# endif

# define MOVE_STEP 1.0
# define ROTATE_STEP 5.0
# define SIZE_STEP 0.5
# define FOV_STEP 5.0
# define BRIGHT_STEP 0.1

# define MIN_SIZE 0.1

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define VALID 1
# define INVALID 0

# define IDENT_A "A"
# define IDENT_C "C"
# define IDENT_L "L"
# define IDENT_SP "sp"
# define IDENT_PL "pl"
# define IDENT_CY "cy"

# define FLAG_A 0b1
# define FLAG_C 0b10
# define FLAG_L 0b100
# define FLAG_SP 0b1000
# define FLAG_PL 0b10000
# define FLAG_CY 0b100000

#endif
