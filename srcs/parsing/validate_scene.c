/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:29:06 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 22:22:30 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	validate_scene(int read_flags)
{
	int	required;

	required = FLAG_A | FLAG_C | FLAG_L;
	if ((read_flags & required) != required)
	{
		if (!(read_flags & FLAG_A))
			print_error(ERR_MSG_MISSING_AMBIENT);
		if (!(read_flags & FLAG_C))
			print_error(ERR_MSG_MISSING_CAMERA);
		if (!(read_flags & FLAG_L))
			print_error(ERR_MSG_MISSING_LIGHT);
		return (INVALID);
	}
	if (!(read_flags & (FLAG_SP | FLAG_PL | FLAG_CY)))
	{
		print_error(ERR_MSG_NO_OBJECTS);
		return (INVALID);
	}
	return (VALID);
}
