/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:29:44 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 19:55:37 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_stack_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first > third)
		rra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
}

void	sort_4(t_stack_node **a, t_stack_node **b)
{
	int	pos;
	int	size;
	int	turn;

	pos = pos_min_idx(*a);
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		turn = pos;
		while (turn--)
			ra(a);
	}
	else
	{
		turn = size - pos;
		while (turn--)
			rra(a);
	}
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

void	sort_5(t_stack_node **a, t_stack_node **b)
{
	int	pos;
	int	size;
	int	turn;

	pos = pos_min_idx(*a);
	size = ft_lstsize(*a);
	if (pos <= size / 2)
	{
		turn = pos;
		while (turn--)
			ra(a);
	}
	else
	{
		turn = size - pos;
		while (turn--)
			rra(a);
	}
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}

void	ft_ultimate_sort(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;

	// ouverture simple (rapide à coder)
	while (ft_lstsize(*a) > 3)
		pb(a, b);
	sort_3(a);
	while (*b)
	{
		update_positions(*a, *b);
		set_targets_for_b(*a, *b);
		compute_costs(*a, *b);
		node = pick_cheapest(*b);
		do_rotations_and_pa(a, b, node->cost_a, node->cost_b);
	}
	final_align_min_to_top(a);
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	size_t	i;

	i = ft_lstsize(*a);
	if (i == 2)
		sa(a);
	else if (i == 3)
		sort_3(a);
	else if (i == 4)
		sort_4(a, b);
	else if (i == 5)
		sort_5(a, b);
	else
		ft_ultimate_sort(a, b);
}

/** TURK ALGO

stack	a = doubly linked list of :

LINKED LIST0
- value in int = the value of the number
- index in int = the position in the stack, from 0 to size of stack
- target in Node*
- bool IsInUpperHalfOFCurrentStack
- next
- prev

stack	b = a doubly linked list of the same


1) put all numbers into stack A

2) put the 2 first numbers into stack B

3) While there is more than 3 numbers in A:

	a) UPDATE INDEX
	Check index (== position dans la stack) of each element in each stack
	Also update if they are IsInUpperHalfOFCurrentStack

	b) FIND TARGET
	find a target in stack B for each number in stack A

	c) CALCULATE COST
	for each number in stack A,
		find the cost in operation if you were to put it on top of its target
		if number and target are both IsInUpperHalfOFCurrentStack or both
		not in IsInUpperHalfOFCurrentStack
			-> try to optimize rr and rrr

	d) DO CHEAPEST
	determine which operation cost the less, and do it

4) TINY SORT for 3
Sort 3 elements in stack A using sa or ra, rra

5) PUSH BACK TO STACK A

	a) FIND TARGET
	find a target in stack A for each number in stack B

	b) CALCULATE COST
	for each number in stack B,
		find the cost in operation if you were to put it on top of its target

	c) DO CHEAPEST
	determine which operation cost the less, and do it

6) Put smallest on top
*/

/*/ TURK ALGO OPTIMIZED


0) Calculate the median value of the numbers you received
Ex: if you received 1, 2, 3, 4, 5, 6, 7, 8, 9, 10000, median is 5


stack	a = doubly linked list of :

LINKED LIST
- value in int
- index in int
- target in Node*
- bool isAboveMedian = check if (value > medianOfAllNumbers),
	depend on value
- bool IsInUpperHalfOFCurrentStack = check if is
	currently in the upper half of a stack,
	depend on index
- next

- prev

stack	b = a doubly linked list of the same


1) put all numbers into stack A

2) put the 2 first numbers into stack B

3) While there is more than 3 numbers in A, for each number

	if number isAboveMedian,
		push to B

	else
		push to B + rrb

	=> B is filled in two block : upper half is big numbers,
		lower half is small numbers


4) TINY SORT for 3
Sort 3 elements in stack A using sa or ra, rra

5) PUSH BACK TO STACK A

	a) FIND TARGET
	find a target in stack A for each number in stack B

	b) CALCULATE COST
	for each number in stack B,
		find the cost in operation if you were to put it on top of its target

	c) DO CHEAPEST
	determine which operation cost the less, and do it

6) Put smallest on top
*/