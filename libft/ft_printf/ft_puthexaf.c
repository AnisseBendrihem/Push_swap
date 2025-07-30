/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexaf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:08:32 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 01:12:57 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthexaf(unsigned long nb, int is_mod)
{
	char	*base;
	int		count;

	count = 0;
	if (is_mod == 'x' || is_mod == 'p')
		base = "0123456789abcdef";
	else if (is_mod == 'X')
		base = "0123456789ABCDEF";
	if (is_mod == 'p')
	{
		if (!nb)
		{
			count += ft_putstrf("(nil)");
			return (count);
		}
		count += ft_putcharf('0');
		count += ft_putcharf('x');
		is_mod = 'x';
	}
	if (nb >= 16)
	{
		count += ft_puthexaf((nb / 16), is_mod);
	}
	count += ft_putcharf(base[nb % 16]);
	return (count);
}
