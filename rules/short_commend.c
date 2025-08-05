/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_commend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:09:56 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/05 08:44:48 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
// Avant : a → [1] → [2] → [3]
// Après : a → [2] → [1] → [3]
void	sa(t_stack_node **a)
{
	swap_node(a);
	ft_printf("sa\n");
}

// sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
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

// ra (rotate a) : Décale d’une position vers le haut tous les éléments de la pile a.
// Le premier élément devient le dernier.
// Avant : a → [1] → [2] → [3]
// Après : a → [2] → [3] → [1]
void	ra(t_stack_node **a)
{
	rotate_node(a);
	ft_printf("ra\n");
}

// rb (rotate b) : Décale d’une position vers le haut tous les éléments de la pile b.
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

// rra (reverse rotate a) : Décale d’une position vers le bas tous les éléments de la pile a.
// Le dernier élément devient le premier.
// Avant : a → [1] → [2] → [3]
// Après : a → [3] → [1] → [2]

void	rra(t_stack_node **a)
{
	reverse_rotate_node(a);
	ft_printf("rra\n");
}

// rrb (reverse rotate b) : Décale d’une position vers le bas tous les éléments de la pile b.
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
