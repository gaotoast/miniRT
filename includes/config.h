/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 21:44:50 by stakada           #+#    #+#             */
/*   Updated: 2025/10/20 12:42:01 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define WIN_WIDTH 1080
# define WIN_HEIGHT 800
# define EXT ".rt"
# define PROGRAM "./miniRT"

# if defined(__APPLE__)
#  define ESC_KEY 53
# else
#  include <X11/keysym.h>
#  define ESC_KEY XK_Escape
# endif

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