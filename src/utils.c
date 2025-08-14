/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 02:27:03 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/09 11:44:06 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_int_tab(int *tab, unsigned int size)
{
	int				tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	lst_to_tab(t_stack_node **src, int *dest)
{
	t_stack_node	*key;
	int				i;

	key = *src;
	i = 0;
	while (key)
	{
		dest[i] = key->value;
		key = key->next;
		i++;
	}
}

void	fill_index_sorted(t_stack_node **a)
{
	t_stack_node *key;
	int *tab;
	int len;
	int i;

	i = 0;
	len = ft_lstsize(*a);
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return ;
	lst_to_tab(a, tab);
	sort_int_tab(tab, len);
	key = *a;
	while (key)
	{
		i = 0;
		while (i < len && tab[i] != key->value)
			i++;
		key->index = i;
		key = key->next;
	}
	free(tab);
}