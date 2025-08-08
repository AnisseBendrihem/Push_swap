/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:44:58 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/08 07:49:26 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	t_stack_node	*key;

	if (!lst)
		return (NULL);
	key = lst;
	while (key->next)
	{
		key = key->next;
	}
	return (key);
}
