/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:29:46 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/05 23:05:22 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Parcing
void	ft_error(int fd);
char	**get_clean_args(int ac, char **av);
int		all_are_valid(char **tab);
int		fill_stack_and_check_overflow(char **tab, t_stack_node **a);
int		has_duplicates(t_stack_node **a);
int		is_sorted(t_stack_node **a);
int		mother_parcing(int ac, char **av, t_stack_node **a);

// Swap operations
void	swap_node(t_stack_node **stack);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);

// Push operations
void	push_node(t_stack_node **src, t_stack_node **dest);

void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);

// Rotate operations
void	rotate_node(t_stack_node **stack);

void	ra(t_stack_node **a);
void	rb(t_stack_node **b);
void	rr(t_stack_node **a, t_stack_node **b);

// Reverse rotate operations
void	reverse_rotate_node(t_stack_node **stack);
void	rra(t_stack_node **a);
void	rrb(t_stack_node **b);
void	rrr(t_stack_node **a, t_stack_node **b);

#endif
