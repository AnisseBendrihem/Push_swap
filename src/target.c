/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:52:36 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 21:42:48 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_target_pos_in_a(t_stack_node *a, int idx_b)
{
	t_stack_node	*key;
	int				best_index;
	int				best_pos;
	int				pos;

	key = a;
	best_index = 2147483647;
	best_pos = -1;
	pos = 0;
	while (key)
	{
		if (key->index > idx_b)
		{
			if (key->index < best_index)
			{
				best_index = key->index;
				best_pos = pos;
			}
		}
		key = key->next;
		pos++;
	}
	if (best_pos != -1)
		return (best_pos);
	return (pos_min_idx(a));
}

void	set_targets_for_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*key;

	key = b;
	while (key)
	{
		key->target_pos = find_target_pos_in_a(a, key->index);
		key = key->next;
	}
}
