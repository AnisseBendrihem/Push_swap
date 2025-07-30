/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:05:59 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 01:09:46 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_convertf(char mod, va_list args)
{
	int		count;
	void	*ptr;

	count = 0;
	if (mod == 'c')
		count += ft_putcharf(va_arg(args, int));
	if (mod == 'd' || mod == 'i')
		count += ft_putnbrf(va_arg(args, int));
	if (mod == '%')
		count = ft_putcharf('%');
	if (mod == 'u')
		count += ft_put_unsigned_nbrf(va_arg(args, unsigned int));
	if (mod == 's')
		count += ft_putstrf(va_arg(args, char *));
	if (mod == 'p')
	{
		ptr = va_arg(args, void *);
		count += ft_puthexaf((unsigned long long)ptr, 'p');
	}
	if (mod == 'x')
		count += ft_puthexaf(va_arg(args, unsigned int), 'x');
	if (mod == 'X')
		count += ft_puthexaf(va_arg(args, unsigned int), 'X');
	return (count);
}
