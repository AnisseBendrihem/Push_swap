/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:53:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/26 07:28:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*mouv;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	mouv = *lst;
	while (mouv->next)
	{
		mouv = mouv->next;
	}
	mouv->next = new;
}
