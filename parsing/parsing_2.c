/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:57:02 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/06 03:41:17 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	fill_stack_and_check_overflow(char **tab, t_stack_node **a)
{
	int				i;
	long			tmp;
	t_stack_node	*security;

	i = 0;
	tmp = 0;
	security = NULL;
	while (tab[i])
	{
		tmp = ft_atol(tab[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
		{
			ft_error(2);
			ft_lstclear(a);
			return (0);
		}
		security = ft_lstnew((int)tmp);
		if (!security)
			return (ft_lstclear(a), 0);
		ft_lstadd_back(a, security);
		lst_set_index(a);
		i++;
	}
	return (i);
}

int	has_duplicates(t_stack_node **a)
{
	t_stack_node	*key;
	t_stack_node	*recip;

	recip = *a;
	while (recip)
	{
		key = recip->next;
		while (key)
		{
			if (recip->value == key->value)
			{
				ft_error(2);
				ft_lstclear(a);
				return (1);
			}
			key = key->next;
		}
		recip = recip->next;
	}
	return (0);
}

int	is_sorted(t_stack_node **a)
{
	t_stack_node	*key;

	key = *a;
	while (key && key->next)
	{
		if (key->value > key->next->value)
			return (0);
		key = key->next;
	}
	ft_lstclear(a);
	return (1);
}

int	mother_parcing(int ac, char **av, t_stack_node **a)
{
	char	**argument;

	argument = get_clean_args(ac, av);
	if (!argument || !all_are_valid(argument))
	{
		ft_free(argument);
		return (1);
	}
	if (!fill_stack_and_check_overflow(argument, a))
	{
		ft_free(argument);
		return (1);
	}
	ft_free(argument);
	if (has_duplicates(a))
		return (1);
	if (is_sorted(a))
		return (1);
	return (0);
}
