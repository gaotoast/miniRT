/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakada <stakada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 14:19:32 by stakada           #+#    #+#             */
/*   Updated: 2026/02/10 16:42:52 by stakada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	*create_object_node(t_obj_type type, void *obj)
{
	t_obj	*node;

	node = (t_obj *)malloc(sizeof(t_obj));
	if (!node)
	{
		perror("");
		return (NULL);
	}
	node->type = type;
	node->obj_data = obj;
	node->next = NULL;
	return (node);
}

int	append_object_to_list(t_obj **objects, t_obj *new)
{
	t_obj	*current;

	if (!objects)
		return (-1);
	if (!*objects)
	{
		*objects = new;
		return (0);
	}
	current = *objects;
	while (current->next)
		current = current->next;
	current->next = new;
	return (0);
}

int	register_object(t_obj **objects, t_obj_type type, void *obj)
{
	t_obj	*new;

	if (!objects || !obj)
		return (-1);
	new = create_object_node(type, obj);
	if (!new)
		return (-1);
	if (append_object_to_list(objects, new) < 0)
	{
		free(new);
		return (-1);
	}
	return (0);
}
