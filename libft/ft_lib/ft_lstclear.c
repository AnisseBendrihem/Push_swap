/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:15:40 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/29 23:38:15 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mouv;
	t_list	*recip;

	if (!lst)
		return ;
	mouv = *lst;
	while (mouv)
	{
		recip = mouv->next;
		if (del)
			del(mouv->content);
		free(mouv);
		mouv = recip;
	}
	*lst = (NULL);
}
