/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:44:58 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:23 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*mouv;

	if (!lst)
		return (NULL);
	mouv = lst;
	while (mouv->next)
	{
		mouv = mouv->next;
	}
	return (mouv);
}
