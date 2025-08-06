/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 23:29:49 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/06 01:17:14 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
// Avant : a → [1] → [2], b → [3] → [4]
// Après : a → [3] → [1] → [2], b → [4]
void	pa(t_stack_node **a, t_stack_node **b)
{
	push_node(b, a);
	ft_printf("pa\n");
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
// Avant : a → [1] → [2], b → [3] → [4]
// Après : a → [2], b → [1] → [3] → [4]
void	pb(t_stack_node **a, t_stack_node **b)
{
	push_node(a, b);
	ft_printf("pb\n");
}
