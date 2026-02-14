/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 20:45:18 by stakada           #+#    #+#             */
/*   Updated: 2026/02/13 18:40:57 by stakada          ###   ########.fr       */
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

int	count_objects(t_obj *objects)
{
	int		count;
	t_obj	*obj;

	count = 0;
	obj = objects;
	while (obj)
	{
		count++;
		obj = obj->next;
	}
	return (count);
}
