/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:42:28 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:28:47 by abendrih         ###   ########.fr       */
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

// Boucle turk te3 zebi :

void	push_opening(t_stack_node **a, t_stack_node **b)
{
	int	median;

	median = ft_lstsize(*a) / 2;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->index <= median)
		{
			pb(a, b);
			if (*b && (*b)->index < median / 2)
				rb(b);
		}
		else
			ra(a);
	}
	sort_3(a);
}

void	update_positions(t_stack_node *a, t_stack_node *b)
{
	int	i;

	i = 0;
	while (a)
	{
		a->pos = i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->pos = i++;
		b = b->next;
	}
}

int	find_target_pos_in_a(t_stack_node *a, int idx_b)
{
	t_stack_node	*cur;
	int				best_index;
	int				best_pos;
	int				pos;

	cur = a;
	best_index = 2147483647;
	best_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->index > idx_b && cur->index < best_index)
		{
			best_index = cur->index;
			best_pos = pos;
		}
		cur = cur->next;
		pos++;
	}
	if (best_index != 2147483647)
		return (best_pos);
	return (pos_min_idx(a));
}

void	update_positions(t_stack_node *a, t_stack_node *b)
{
	int				i;
	int				size;
	t_stack_node	*cur;

	size = ft_lstsize(a);
	i = 0;
	cur = a;
	while (cur)
	{
		cur->pos = i;
		i++;
		cur = cur->next;
	}
	size = ft_lstsize(b);
	i = 0;
	cur = b;
	while (cur)
	{
		cur->pos = i;
		i++;
		cur = cur->next;
	}
}
int	find_target_pos_in_a(t_stack_node *a, int idx_b)
{
	t_stack_node	*cur;
	int				best_index;
	int				best_pos;
	int				pos;

	cur = a;
	best_index = 2147483647;
	best_pos = -1;
	pos = 0;
	while (cur)
	{
		if (cur->index > idx_b)
		{
			if (cur->index < best_index)
			{
				best_index = cur->index;
				best_pos = pos;
			}
		}
		cur = cur->next;
		pos++;
	}
	if (best_pos != -1)
		return (best_pos);
	return (pos_min_idx(a));
}

void	set_targets_for_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur;

	cur = b;
	while (cur)
	{
		cur->target_pos = find_target_pos_in_a(a, cur->index);
		cur = cur->next;
	}
}
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

static int	abs_i2(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	effective_cost(int ca, int cb)
{
	int	a;
	int	b;

	a = abs_i2(ca);
	b = abs_i2(cb);
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
	t_stack_node	*cur;
	int				best_cost;
	int				ec;

	best = NULL;
	best_cost = 2147483647;
	cur = b;
	while (cur)
	{
		ec = effective_cost(cur->cost_a, cur->cost_b);
		if (ec < best_cost)
		{
			best_cost = ec;
			best = cur;
		}
		cur = cur->next;
	}
	return (best);
}

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

void	final_align_min_to_top(t_stack_node **a)
{
	int size;
	int pos;
	int turn;

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