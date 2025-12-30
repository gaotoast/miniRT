/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:42:37 by stakada           #+#    #+#             */
/*   Updated: 2025/12/30 16:37:23 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_error(char *msg, ...)
{
	va_list	ap;

	va_start(ap, msg);
	write(STDERR_FILENO, "Error\n", 6);
	ft_vdprintf(STDERR_FILENO, msg, ap);
	write(STDERR_FILENO, "\n", 1);
	va_end(ap);
}
