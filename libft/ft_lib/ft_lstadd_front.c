/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:52:40 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/08 08:09:50 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*key;

	if (!new)
		return ;
	key = *lst;
	new->prev = NULL;
	new->next = *lst;
	if (key)
		key->prev = new;
	*lst = new;
}
