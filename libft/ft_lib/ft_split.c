/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:33:15 by abendrih          #+#    #+#             */
/*   Updated: 2025/08/01 04:55:18 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(const char *s, int c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*buffer_words(const char *s, int c, int *j)
{
	char	*recip;
	size_t	start;
	size_t	len;
	size_t	i;

	while (s[*j] && s[*j] == c)
		(*j)++;
	start = *j;
	while (s[*j] && s[*j] != c)
		(*j)++;
	len = *j - start;
	recip = malloc(sizeof(char) * (len + 1));
	if (!recip)
		return (NULL);
	i = 0;
	while (i < len)
	{
		recip[i] = s[start + i];
		i++;
	}
	recip[i] = '\0';
	return (recip);
}

char	**ft_split(const char *s, char c)
{
	char	**tab;
	int		words;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		tab[i] = buffer_words(s, c, &j);
		if (!tab[i])
		{
			ft_free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
