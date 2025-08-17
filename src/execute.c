/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:54:48 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:57:45 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// suppose que rr/rrr existent et printent "rr"/"rrr" une seule fois.
static void	do_combo_rotations(t_stack_node **a, t_stack_node **b, int *ca,
		int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		rr(a, b);
		*ca = *ca - 1;
		*cb = *cb - 1;
	}
	while (*ca < 0 && *cb < 0)
	{
		rrr(a, b);
		*ca = *ca + 1;
		*cb = *cb + 1;
	}
}

static void	finish_rot_a(t_stack_node **a, int *ca)
{
	while (*ca > 0)
	{
		ra(a);
		*ca = *ca - 1;
	}
	while (*ca < 0)
	{
		rra(a);
		*ca = *ca + 1;
	}
}

static void	finish_rot_b(t_stack_node **b, int *cb)
{
	while (*cb > 0)
	{
		rb(b);
		*cb = *cb - 1;
	}
	while (*cb < 0)
	{
		rrb(b);
		*cb = *cb + 1;
	}
}

void	do_rotations_and_pa(t_stack_node **a, t_stack_node **b, int ca, int cb)
{
	do_combo_rotations(a, b, &ca, &cb);
	finish_rot_a(a, &ca);
	finish_rot_b(b, &cb);
	pa(a, b);
}
