/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:09:24 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/26 07:28:34 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*key;

	key = malloc(sizeof(t_list));
	if (!key)
		return (NULL);
	key->content = content;
	key->next = NULL;
	return (key);
}
