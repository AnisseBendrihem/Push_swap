/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:05:54 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/03 23:41:17 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_stack_node *lst, void (*f)(void *))
{
	t_stack_node	*mouv;

	if (!lst || !f)
		return ;
	mouv = lst;
	while (mouv)
	{
		f(mouv->value);
		mouv = mouv->next;
	}
}
