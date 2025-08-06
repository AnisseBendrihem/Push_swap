/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:29:50 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/06 03:36:49 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// CODER  ft_ultimate_sort

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
	{
		ft_error(2);
		return (0);
	}
	if (!mother_parcing(ac, av, &a))
	{
		ft_printf("Let's Start !!\n");
		push_swap(&a, &b);
	}
	return (0);
}

// int	main(void)
// {
// 	t_stack_node	*a;
// 	t_stack_node	*key;
// 	t_stack_node	*b;

// 	a = NULL;
// 	b = NULL;
// 	ft_lstadd_back(&a, ft_lstnew(1));
// 	ft_lstadd_back(&a, ft_lstnew(2));
// 	ft_lstadd_back(&a, ft_lstnew(3));
// 	ft_lstadd_back(&b, ft_lstnew(4));
// 	ft_lstadd_back(&b, ft_lstnew(5));
// 	ft_lstadd_back(&b, ft_lstnew(6));
// 	key = a;
// 	printf("liste a : \n");
// 	while (key)
// 	{
// 		printf("%d\n", key->value);
// 		key = key->next;
// 	}
// 	printf("liste b : \n");
// 	key = b;
// 	while (key)
// 	{
// 		printf("%d\n", key->value);
// 		key = key->next;
// 	}
// 	printf("Apres la commande\n");
// 	rrr(&a, &b);
// 	printf("liste a : \n");
// 	key = a;
// 	while (key)
// 	{
// 		printf("%d\n", key->value);
// 		key = key->next;
// 	}
// 	printf("liste b : \n");
// 	key = b;
// 	while (key)
// 	{
// 		printf("%d\n", key->value);
// 		key = key->next;
// 	}
// }
