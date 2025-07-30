/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:49:34 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 01:15:09 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		last_count;
	int		i;

	if (!str)
	{
		return (-1);
	}
	i = 0;
	last_count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			last_count += ft_convertf(str[i + 1], args);
			i++;
		}
		else
		{
			last_count += ft_putcharf(str[i]);
		}
		i++;
	}
	return (last_count);
}
