/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:55:09 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:57:47 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	final_align_min_to_top(t_stack_node **a)
{
	int	size;
	int	pos;
	int	turn;

	size = ft_lstsize(*a);
	pos = pos_min_idx(*a);
	if (pos <= size / 2)
	{
		turn = pos;
		while (turn > 0)
		{
			ra(a);
			turn--;
		}
	}
	else
	{
		turn = size - pos;
		while (turn > 0)
		{
			rra(a);
			turn--;
		}
	}
}
