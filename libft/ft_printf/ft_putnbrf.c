/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:09:26 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 01:11:49 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbrf(int n)
{
	unsigned int	nb;
	int				count;

	count = 0;
	if (n < 0)
	{
		count += ft_putcharf('-');
		n = -n;
	}
	nb = n;
	if (nb >= 10)
	{
		count += ft_putnbrf(nb / 10);
	}
	count += ft_putcharf(nb % 10 + '0');
	return (count);
}
