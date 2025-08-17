/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:46:53 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 03:07:36 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	ln = n;
	if (ln < 0)
	{
		ln *= -1;
		write(fd, "-", 1);
	}
	if (ln >= 10)
		ft_putnbr_fd(ln / 10, fd);
	c = ln % 10 + '0';
	write(fd, &c, 1);
}
