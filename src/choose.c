/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:54:06 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:57:39 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	abs_i(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	effective_cost(int ca, int cb)
{
	int	a;
	int	b;

	a = abs_i(ca);
	b = abs_i(cb);
	if ((ca >= 0 && cb >= 0) || (ca < 0 && cb < 0))
	{
		if (a > b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}

t_stack_node	*pick_cheapest(t_stack_node *b)
{
	t_stack_node	*best;
	int				best_cost;
	int				ec;

	best = NULL;
	best_cost = 2147483647;
	while (b)
	{
		ec = effective_cost(b->cost_a, b->cost_b);
		if (ec < best_cost)
		{
			best_cost = ec;
			best = b;
		}
		b = b->next;
	}
	return (best);
}
