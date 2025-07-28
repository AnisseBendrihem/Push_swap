/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:15:40 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/26 07:28:31 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mouv;
	t_list	*recip;

	if (!lst || !del)
		return ;
	mouv = *lst;
	while (mouv)
	{
		recip = mouv->next;
		del(mouv->content);
		free(mouv);
		mouv = recip;
	}
	*lst = (NULL);
}
