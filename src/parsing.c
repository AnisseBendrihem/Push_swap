/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:57:02 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/05 08:56:29 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**get_clean_args(int ac, char **av)
{
	char	**argument;
	int		i;

	i = 0;
	if (ac == 2)
	{
		argument = ft_split(av[1], 32);
		if (!argument || !argument[0])
		{
			ft_free(argument);
			ft_printf("Error : Empty argument2\n");
			return (NULL);
		}
	}
	else if (ac > 2)
	{
		argument = malloc(sizeof(char *) * (ac));
		if (!argument)
			return (NULL);
		while (i < ac - 1)
		{
			argument[i] = ft_strdup(av[i + 1]);
			i++;
		}
		argument[i] = NULL;
	}
	return (argument);
}

int	is_valid_number(const char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	if ((s[i] == '+' || s[i] == '-') && ft_isdigit(s[i + 1]))
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	all_are_valid(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (!is_valid_number(tab[i]))
		{
			ft_printf("Error : Invalid Number\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	fill_and_check_overflow(char **tab, t_stack_node **a)
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
			ft_printf("Error : Int Overflow\n");
			ft_lstclear(a);
			return (0);
		}
		security = ft_lstnew((int)tmp);
		if (!security)
			return (ft_lstclear(a), 0);
		ft_lstadd_back(a, security);
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
				ft_printf("Error : Duplicate number");
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
	ft_printf("All number are sorted !!\n");
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
	if (!fill_and_check_overflow(argument, a))
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


