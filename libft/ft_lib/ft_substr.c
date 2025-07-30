/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:27:34 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:13:31 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strmdup(const char *src, size_t n, unsigned int t)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = src[t + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, int start, size_t len)
{
	char	*result;
	size_t	lensecour;

	lensecour = ft_strlen(s) - start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		result = malloc(sizeof(char) * 1);
		if (!result)
			return (NULL);
		*result = '\0';
		return (result);
	}
	if (len > lensecour)
	{
		result = ft_strmdup(s, lensecour, start);
		return (result);
	}
	result = ft_strmdup(s, len, start);
	return (result);
}
