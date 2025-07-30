/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:56:12 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:37 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		*dtr;

	i = 0;
	str = (const unsigned char *)src;
	dtr = (unsigned char *)dst;
	if (dtr == 0 && str == 0)
		return (0);
	while (i < n)
	{
		dtr[i] = str[i];
		i++;
	}
	return (dst);
}
