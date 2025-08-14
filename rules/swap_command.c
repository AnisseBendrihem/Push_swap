/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:30:32 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/12 17:49:13 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_node(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;
	t_stack_node	*third;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	third = second->next;
	if (third)
	{
		third->prev = first;
		first->next = third;
	}
	else
		first->next = NULL;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
}

// sa (swap a) :
// Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// Avant : a → [1] → [2] → [3]
// Après : a → [2] → [1] → [3]
void	sa(t_stack_node **a)
{
	swap_node(a);
	ft_printf("sa\n");
}

// sb (swap b ) :
// Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// Avant : b → [4] → [5] → [6]
// Après : b → [5] → [4] → [6]
void	sb(t_stack_node **b)
{
	swap_node(b);
	ft_printf("sb\n");
}

// ss : sa et sb en même temps.
// Avant : a → [1] → [2], b → [4] → [5]
// Après : a → [2] → [1], b → [5] → [4]
void	ss(t_stack_node **a, t_stack_node **b)
{
	swap_node(a);
	swap_node(b);
	ft_printf("ss\n");
}
