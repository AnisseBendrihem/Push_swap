/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:30:45 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/05 08:44:35 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_node(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}


void	push_node(t_stack_node **src, t_stack_node **dest)
{
	t_stack_node	*first;

	if (!src || !(*src))
		return ;
	first = *src;
	*src = first->next;
	first->next = *dest;
	*dest = first;
}


void	rotate_node(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || (!*stack) || !(*stack)->next)
		return ;
	last = *stack;
	first = (*stack)->next;
	*stack = first;
	while (first->next)
		first = first->next;
	first->next = last;
	last->next = NULL;
}


void	reverse_rotate_node(t_stack_node **stack)
{
	t_stack_node	*second_to_last;
	t_stack_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	second_to_last = NULL;
	last = *stack;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	second_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

