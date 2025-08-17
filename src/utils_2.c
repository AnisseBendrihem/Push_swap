/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:42:28 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:48:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// psition du plus petit nombre dans la pile
int	pos_min_idx(t_stack_node *a)
{
	t_stack_node	*key;
	int				pos;
	int				best_pos;
	int				best_index;

	key = a;
	pos = 0;
	best_pos = 0;
	best_index = 2147483647;
	if (!a)
		return (-1);
	while (key)
	{
		if (key->index < best_index)
		{
			best_pos = pos;
			best_index = key->index;
		}
		pos++;
		key = key->next;
	}
	return (best_pos);
}

// position du plus grand nombre dans la pile
int	pos_max_idx(t_stack_node *a)
{
	t_stack_node	*key;
	int				pos;
	int				best_pos;
	int				best_index;

	key = a;
	pos = 0;
	best_pos = 0;
	best_index = -1;
	if (!a)
		return (-1);
	while (key)
	{
		if (key->index > best_index)
		{
			best_pos = pos;
			best_index = key->index;
		}
		pos++;
		key = key->next;
	}
	return (best_pos);
}
