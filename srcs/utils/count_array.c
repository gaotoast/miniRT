/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:45:18 by stakada           #+#    #+#             */
/*   Updated: 2025/08/28 13:09:46 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	count_array(char **array)
{
	int	cnt;

	if (!array)
		return (0);
	cnt = 0;
	while (array[cnt])
		cnt++;
	return (cnt);
}
