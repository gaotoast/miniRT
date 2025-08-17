/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kinamura <kinamura@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:08:11 by kinamura          #+#    #+#             */
/*   Updated: 2024/09/03 23:50:06 by kinamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new;
	t_list	*transformed_content;

	if (!f || !del)
		return (NULL);
	node = NULL;
	while (lst)
	{
		transformed_content = (*f)(lst->content);
		new = ft_lstnew(transformed_content);
		if (!new)
		{
			ft_lstclear(&node, del);
			del(transformed_content);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&node, new);
		lst = lst->next;
	}
	return (node);
}
