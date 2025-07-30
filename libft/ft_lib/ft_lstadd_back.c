/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:53:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:12 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
