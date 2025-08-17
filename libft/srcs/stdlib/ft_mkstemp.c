/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mkstemp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 02:59:09 by kinamura          #+#    #+#             */
/*   Updated: 2025/07/20 14:32:48 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mkstemp(char *template)
{
	return (open(ft_mktemp(template), O_RDWR | O_CREAT | O_EXCL, 0600));
}
