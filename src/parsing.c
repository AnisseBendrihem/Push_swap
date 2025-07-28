/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:57:02 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/27 23:35:21 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	parse_arguments(int ac, char **av, t_stack_node **a)
{
	t_stack_node	*key;
	int				i;
	int				r;
	char			**slip;

	i = 0;
	r = 0;
	key = *a;
	if (ac < 2)
		return (write(1, "Error\n", 6), 0);
	else if (ac == 2)
	{
		slip = ft_split(av[1]);
		while (slip[i])
		{
			r = ft_atoi(slip[i]);
			ft_add_back(a, ft_lst_new(r));
			free(slip[i]);
			i++;
		}
		free(slip);
		return (i);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			r = ft_atoi(av[i]);
			ft_add_back(a, ft_lst_new(r));
			i++;
		}
		return (i - 1);
	}
}

int	below_intmax(char *int_word)
{
	const char	*int_max = "2147483647";
	int			i;
	int			len;

	len = ft_strlen(int_word);
	if (int_word[0] == '-' || len < 10)
		return (1);
	else if (len > 10)
		return (0);
	else
	{
		i = 0;
		while (i < len)
		{
			if (int_word[i] > int_max[i])
				return (0);
			else if (int_word[i] < int_max[i])
				break ;
			i++;
		}
		return (1);
	}
}

int	digit_error(char *int_word)
{
	int	i;

	i = 0;
	while (int_word[i])
	{
		if (!ft_isdigit(int_word[i]))
		{
			printf("digit error: %c\n", int_word[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	arg_error(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (digit_error(av[i]) || !below_intmax(av[i]))
			return (1);
		i++;
	}
	return (0);
}
