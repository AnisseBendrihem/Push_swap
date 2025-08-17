/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:53:30 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 21:38:28 by abendrih         ###   ########.fr       */
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
	t_stack_node	*key;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	key = b;
	while (key)
	{
		key->cost_b = signed_cost(key->pos, size_b);
		key->cost_a = signed_cost(key->target_pos, size_a);
		key = key->next;
	}
}
