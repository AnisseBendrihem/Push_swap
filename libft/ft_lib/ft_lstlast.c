/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:44:58 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/03 23:39:44 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	t_stack_node	*mouv;

	if (!lst)
		return (NULL);
	mouv = lst;
	while (mouv->next)
	{
		mouv = mouv->next;
	}
	return (mouv);
}
