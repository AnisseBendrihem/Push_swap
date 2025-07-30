/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:04:56 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:12:09 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	break_num(int n)
{
	int		i;
	long	nb;

	nb = n;
	i = 1;
	if (n < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*recip;
	int		len;
	long	nb;

	len = break_num(n);
	recip = malloc(sizeof(char) * (len + 1));
	if (!recip)
		return (NULL);
	nb = n;
	recip[len] = '\0';
	len--;
	if (nb < 0)
	{
		recip[0] = '-';
		nb = -nb;
	}
	while (len >= 0)
	{
		recip[len] = nb % 10 + '0';
		nb = nb / 10;
		if (recip[0] == '-' && len == 1)
			break ;
		len--;
	}
	return (recip);
}
