/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:52:09 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/17 21:42:24 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	update_positions(t_stack_node *a, t_stack_node *b)
{
	int				i;
	t_stack_node	*key;

	i = 0;
	key = a;
	while (key)
	{
		key->pos = i;
		i++;
		key = key->next;
	}
	i = 0;
	key = b;
	while (key)
	{
		key->pos = i;
		i++;
		key = key->next;
	}
}
