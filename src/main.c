/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:29:50 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/08 13:55:22 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// CODER  ft_ultimate_sort

// int	main(int ac, char **av)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	if (ac < 2)
// 	{
// 		ft_error(2);
// 		return (0);
// 	}
// 	if (!mother_parcing(ac, av, &a))
// 		push_swap(&a, &b);
// 	return (0);
// }

int	main(void)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_stack_node	*c;
	t_stack_node	*key;

	a = ft_lstnew(1);
	b = ft_lstnew(2);
	c = ft_lstnew(3);
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	rra(&a);
	key = a;
	while (key)
	{
		ft_printf("%d\n", key->value);
		key = key->next;
	}
	ft_printf("----------\n");
	key = ft_lstlast(a);
	while (key)
	{
		ft_printf("%d\n", key->value);
		key = key->prev;
	}
}
