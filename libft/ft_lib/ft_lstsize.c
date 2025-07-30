/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:32:59 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:30 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*mouv;

	i = 0;
	mouv = lst;
	while (mouv)
	{
		mouv = mouv->next;
		i++;
	}
	return (i);
}
