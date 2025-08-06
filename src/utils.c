/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 02:27:03 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/06 03:32:17 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	lst_find_min(t_stack_node *stack)
{
	t_stack_node	*key;
	int				i;

	i = stack->value;
	key = stack;
	while (key)
	{
		if (i > key->value)
			i = key->value;
		key = key->next;
	}
	return (i);
}

void	lst_set_index(t_stack_node **stack)
{
	t_stack_node	*key;
	int				i;

	if (!stack || !(*stack))
		return ;
	key = *stack;
	i = 0;
	while (key)
	{
		key->index = i++;
		key = key->next;
	}
}

int	lst_position(t_stack_node *stack, int value)
{
	t_stack_node	*key;

	key = stack;
	while (key)
	{
		if (key->value == value)
			return (key->index);
		key = key->next;
	}
	return (-1);
}
