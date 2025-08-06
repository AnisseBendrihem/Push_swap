/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:29:34 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/06 03:40:57 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(int fd)
{
	write(fd, "Error\n", 6);
}

char	**get_clean_args(int ac, char **av)
{
	char	**argument;
	int		i;

	i = 0;
	if (ac == 2)
	{
		argument = ft_split(av[1], 32);
		if (!argument || !argument[0])
			return (ft_free(argument), ft_error(2), NULL);
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
			ft_error(2);
			return (0);
		}
		i++;
	}
	return (1);
}
