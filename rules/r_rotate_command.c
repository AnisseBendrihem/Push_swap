/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:31:25 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/05 23:34:01 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

// rra (reverse rotate a) :
// Décale d’une position vers le bas tous les éléments de la pile a.
// Le dernier élément devient le premier.
// Avant : a → [1] → [2] → [3]
// Après : a → [3] → [1] → [2]
void	rra(t_stack_node **a)
{
	reverse_rotate_node(a);
	ft_printf("rra\n");
}

// rrb (reverse rotate b) :
// Décale d’une position vers le bas tous les éléments de la pile b.
// Le dernier élémen-t devient le premier.
// Avant : b → [4] → [5] → [6]
// Après : b → [6] → [4] → [5]
void	rrb(t_stack_node **b)
{
	reverse_rotate_node(b);
	ft_printf("rrb\n");
}

// rrr : rra et rrb en même temps.
// Avant : a → [1] → [2], b → [4] → [5]
// Après : a → [2] → [1], b → [5] → [4]
void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate_node(a);
	reverse_rotate_node(b);
	ft_printf("rrr\n");
}
