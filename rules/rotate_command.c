/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:30:45 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/05 00:21:29 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// Avant : a → [1] → [2] → [3]
// Après : a → [2] → [1] → [3]
void	sa(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = *a;
	*a = second;
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// Avant : b → [4] → [5] → [6]
// Après : b → [5] → [4] → [6]
void	sb(t_stack_node **b)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = second->next;
	second->next = *b;
	*b = second;
}

// ss : sa et sb en même temps.
// Avant : a → [1] → [2], b → [4] → [5]
// Après : a → [2] → [1], b → [5] → [4]
void	ss(t_stack_node **a, t_stack_node **b)
{
	sa(a);
	sb(b);
}

// pa (push a) : Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
// Avant : a → [1] → [2], b → [3] → [4]
// Après : a → [3] → [1] → [2], b → [4]
void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!b || !*b)
		return ;
	first = *b;
	second = (*b)->next;
	first->next = *a;
	*b = second;
	*a = first;
}

// pb (push b) : Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
// Avant : a → [1] → [2], b → [3] → [4]
// Après : a → [2], b → [1] → [3] → [4]
void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*first;

	if (!a || !*a)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = *b;
	*b = first;
}

// ra (rotate a) : Décale d’une position vers le haut tous les éléments de la pile a.
// Le premier élément devient le dernier.
// Avant : a → [1] → [2] → [3]
// Après : a → [2] → [3] → [1]
void	ra(t_stack_node **a)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	first = (*a)->next;
	(*a) = first;
	last->next = NULL;
	while (first->next)
		first = first->next;
	first->next = last;
}

// rb (rotate b) : Décale d’une position vers le haut tous les éléments de la pile b.
// Le premier élément devient le dernier.
// Avant : b → [4] → [5] → [6]
// Après : b → [5] → [6] → [4]
void	rb(t_stack_node **b)
{
	t_stack_node	*end;
	t_stack_node	*start;

	if (!*b || !(*b)->next)
		return ;
	end = *b;
	start = (*b)->next;
	*b = start;
	while (start->next)
		start = start->next;
	start->next = end;
	end->next = NULL;
}

// rr : ra et rb en même temps.
// Avant : a → [1] → [2], b → [4] → [5]
// Après : a → [2] → [1], b → [5] → [4]
void	rr(t_stack_node **a, t_stack_node **b)
{
	rb(b);
	ra(a);
}

// rra (reverse rotate a) : Décale d’une position vers le bas tous les éléments de la pile a.
// Le dernier élément devient le premier.
// Avant : a → [1] → [2] → [3]
// Après : a → [3] → [1] → [2]
void	rra(t_stack_node **a)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	while (first->next->next)
		first = first->next;
	last = first->next;
	first->next = NULL;
	last->next = *a;
	*a = last;
}

// rrb (reverse rotate b) : Décale d’une position vers le bas tous les éléments de la pile b.
// Le dernier élément devient le premier.
// Avant : b → [4] → [5] → [6]
// Après : b → [6] → [4] → [5]
void	rrb(t_stack_node **b)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	while (first->next)
	{
		last = first;
		first = first->next;
	}
	last->next = NULL;
	first->next = *b;
	*b = first;
}

// rrr : rra et rrb en même temps.
// Avant : a → [1] → [2], b → [4] → [5]
// Après : a → [2] → [1], b → [5] → [4]
void	rrr(t_stack_node **b, t_stack_node **a)
{
	rrb(b);
	rra(a);
}
