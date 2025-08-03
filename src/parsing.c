/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:57:02 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/03 22:41:53 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**get_clean_args(int ac, char **av)
{
	char	**argument;
	int		i;

	i = 0;
	if (ac == 2)
		argument = ft_split(av[1], 32);
	else if (ac > 2)
	{
		argument = malloc(sizeof(char *) * (ac));
		argument[ac - 1] = NULL;
		if (!argument)
			return (NULL);
		while (i < ac)
		{
			argument[i] = av[i + 1];
			i++;
		}
	}
	return (argument);
}

int	is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	all_are_valid(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!is_valid_number(tab[i]))
		{
			ft_free(tab);
			return (0);
		}
		i++;
	}
	return (1);
}

int	fill_and_size_of_stack(char **tab, t_stack_node **a)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = 0;
	while (tab[i])
	{
		tmp = ft_atol(tab[i]);
		ft_lstadd_back(a, ft_lstnew(tmp));
		i++;
	}
	ft_free(tab);
	return (i);
}

int	check_limits(t_stack_node *a)
{
	t_stack_node	*key;

	key = a;
	while (key)
	{
		if (key->value > 2147483647 || key->value < -2147483648)
		{
			ft_lstclear(a, NULL);
			return (1);
		}
		key = key->next;
	}
	return (0);
}

int	has_duplicates(t_stack_node *a)
{
	t_stack_node	*key;
	t_stack_node	*recip;

	recip = a;
	while (recip)
	{
		key = recip->next;
		while (key)
		{
			if (recip->value == key->value)
			{
				ft_lstclear(a, NULL);
				return (1);
			}
			key = key->next;
		}
		recip = recip->next;
	}
	return (0);
}

int	is_sorted(t_stack_node *a)
{
	t_stack_node	*key;

	key = a;
	while (key && key->next)
	{
		if (key->value > key->next->value)
		{
			ft_lstclear(a, NULL);
			return (0);
		}
		key = key->next;
	}
	return (1);
}

// crer la fonction cerveau qui link tou ca et la call dans le main
// corriger les regles sa ect..
// commencer le tri