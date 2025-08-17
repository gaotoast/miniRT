/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:14:04 by ubuntu            #+#    #+#             */
/*   Updated: 2025/07/20 03:09:00 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array2(void **array)
{
	size_t	index;

	index = 0;
	if (!array)
		return ;
	while (array[index] != NULL)
	{
		free(array[index]);
		index++;
	}
	free(array);
}
