/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:42:37 by stakada           #+#    #+#             */
/*   Updated: 2025/08/22 14:00:30 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_error(char *msg)
{
	write(STDERR_FILENO, "Error\n", 6);
	ft_dprintf(STDERR_FILENO, msg);
	write(STDERR_FILENO, "\n", 1);
}
