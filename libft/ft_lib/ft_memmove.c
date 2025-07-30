/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:58:18 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:40 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		*dtr;

	i = len;
	str = (const unsigned char *)src;
	dtr = (unsigned char *) dst;
	if (dst == 0 && str == 0)
		return (0);
	if (dtr > str)
	{
		while (i > 0)
		{
			i--;
			dtr[i] = str[i];
		}
	}
	else
		ft_memcpy(dtr, str, len);
	return (dst);
}
