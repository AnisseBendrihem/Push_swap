/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:09:24 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/05 03:05:55 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack_node	*ft_lstnew(int value)
{
	t_stack_node	*key;

	key = malloc(sizeof(t_stack_node));
	if (!key)
		return (NULL);
	key->value = value;
	key->next = NULL;
	return (key);
}
