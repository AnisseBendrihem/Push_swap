/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:52:09 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:58:07 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_positions(t_stack_node *a, t_stack_node *b)
{
	int				i;
	t_stack_node	*cur;

	i = 0;
	cur = a;
	while (cur)
	{
		cur->pos = i;
		i++;
		cur = cur->next;
	}
	i = 0;
	cur = b;
	while (cur)
	{
		cur->pos = i;
		i++;
		cur = cur->next;
	}
}
