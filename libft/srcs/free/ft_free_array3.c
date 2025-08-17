/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 03:13:46 by ubuntu            #+#    #+#             */
/*   Updated: 2025/07/20 03:09:02 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array3(void ***array)
{
	size_t	size;
	size_t	index;

	size = 0;
	if (!array)
		return ;
	while (array[size] != NULL)
	{
		index = 0;
		while (array[size][index] != NULL)
		{
			free(array[size][index]);
			index++;
		}
		free(array[size]);
		size++;
	}
	free(array);
}
