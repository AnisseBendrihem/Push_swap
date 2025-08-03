/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:53:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/03 23:39:17 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*mouv;

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
