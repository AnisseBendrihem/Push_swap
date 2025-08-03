/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:15:40 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/03 23:42:35 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_stack_node **lst)
{
	t_stack_node	*recip;
	t_stack_node	*key;

	if (!lst || !*lst)
		return ;
	key = *lst;
	while (key)
	{
		recip = key;
		key = key->next;
		free(recip);
	}
	*lst = (NULL);
}
