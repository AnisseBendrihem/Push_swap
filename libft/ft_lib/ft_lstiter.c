/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 22:05:54 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:21 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*mouv;

	if (!lst || !f)
		return ;
	mouv = lst;
	while (mouv)
	{
		f(mouv->content);
		mouv = mouv->next;
	}
}
