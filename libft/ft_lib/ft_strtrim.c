/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 00:19:12 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:13:29 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s2;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s2 = malloc(sizeof(char) * ((end - start) + 1));
	if (!s2)
		return (NULL);
	while (i < end - start)
	{
		s2[i] = s1[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
