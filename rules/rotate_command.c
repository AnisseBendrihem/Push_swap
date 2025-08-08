/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:31:10 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/08 13:43:40 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_node(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!stack || (!*stack) || !(*stack)->next)
		return ;
	last = *stack;
	first = (*stack)->next;
	first->prev = NULL;
	*stack = first;
	while (first->next)
		first = first->next;
	last->prev = first;
	first->next = last;
	last->next = NULL;
}

// ra (rotate a) :
// Décale d’une position vers le haut tous les éléments de la pile a.
// Le premier élément devient le dernier.
// Avant : a → [1] → [2] → [3]
// Après : a → [2] → [3] → [1]
void	ra(t_stack_node **a)
{
	rotate_node(a);
	ft_printf("ra\n");
}

// rb (rotate b) :
// Décale d’une position vers le haut tous les éléments de la pile b.
// Le premier élément devient le dernier.
// Avant : b → [4] → [5] → [6]
// Après : b → [5] → [6] → [4]
void	rb(t_stack_node **b)
{
	rotate_node(b);
	ft_printf("rb\n");
}

// rr : ra et rb en même temps.
// Avant : a → [1] → [2], b → [4] → [5]
// Après : a → [2] → [1], b → [5] → [4]
void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate_node(a);
	rotate_node(b);
	ft_printf("rr\n");
}
