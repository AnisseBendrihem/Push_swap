/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:32:59 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/06 03:32:43 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_stack_node *lst)
{
	int				i;
	t_stack_node	*mouv;

	i = 0;
	mouv = lst;
	while (mouv)
	{
		mouv = mouv->next;
		i++;
	}
	return (i);
}
