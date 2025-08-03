/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:00:56 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/03 23:42:47 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack_node	*ft_lstmap(t_stack_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack_node	*new_list;
	t_stack_node	*new_bloc;

	if (!lst || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (f)
			new_bloc = ft_lstnew((*f)(lst->value));
		else
			new_bloc = ft_lstnew(lst->value);
		if (!new_bloc)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_bloc);
		lst = lst->next;
	}
	return (new_list);
}
