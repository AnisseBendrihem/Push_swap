/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 23:09:24 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:27 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
