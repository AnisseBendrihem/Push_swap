/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:53:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/04 03:43:13 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*key;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	key = *lst;
	while (key->next)
	{
		key = key->next;
	}
	key->next = new;
}
