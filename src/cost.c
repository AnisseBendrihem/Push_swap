/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:53:30 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:57:41 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	signed_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	compute_costs(t_stack_node *a, t_stack_node *b)
{
	int				size_a;
	int				size_b;
	t_stack_node	*cur;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	cur = b;
	while (cur)
	{
		cur->cost_b = signed_cost(cur->pos, size_b);
		cur->cost_a = signed_cost(cur->target_pos, size_a);
		cur = cur->next;
	}
}
