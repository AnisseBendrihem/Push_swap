/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:00:56 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_bloc;

	if (!lst || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (f)
			new_bloc = ft_lstnew((*f)(lst->content));
		else
			new_bloc = ft_lstnew(lst->content);
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
