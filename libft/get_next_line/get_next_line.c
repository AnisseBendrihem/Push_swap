/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:56:24 by abendrih          #+#    #+#             */
/*   Updated: 2025/07/28 02:11:24 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	lenof_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*extract_line(char **s_recip, char **r_recip)
{
	char	*tmp_recip;

	if (!*s_recip)
	{
		*s_recip = ft_strndup(*r_recip, ft_strlen(*r_recip));
		if (!*s_recip)
			return (NULL);
	}
	else
	{
		tmp_recip = ft_strjoin(*s_recip, *r_recip);
		if (!tmp_recip)
			return (NULL);
		*s_recip = tmp_recip;
	}
	return (*s_recip);
}

char	*next_and_free(char **s_recip, int bytes_read)
{
	char	*line;
	char	*tmp_recip;
	int		len;

	if (bytes_read == 0 && *s_recip && **s_recip)
	{
		line = ft_strndup(*s_recip, ft_strlen(*s_recip));
		if (!line)
			return (NULL);
		return (free(*s_recip), *s_recip = NULL, line);
	}
	else if (ft_strchr(*s_recip, '\n') != NULL)
	{
		len = lenof_newline(*s_recip) + 1;
		line = ft_strndup(*s_recip, len);
		if (!line)
			return (free(*s_recip), NULL);
		tmp_recip = ft_strndup(&(*s_recip)[len], ft_strlen(&(*s_recip)[len]));
		free(*s_recip);
		if (!tmp_recip)
			return (free(line), NULL);
		return (*s_recip = tmp_recip, line);
	}
	else
		return (NULL);
}

int	init_var(int fd, char **final_line, char **r_recip, ssize_t *bytes_read)
{
	*final_line = NULL;
	*r_recip = NULL;
	*bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*s_recip[1024] = {0};
	char		*final_line;
	char		*r_recip;
	ssize_t		bytes_read;

	if (init_var(fd, &final_line, &r_recip, &bytes_read) == 0)
		return (NULL);
	while (bytes_read != 0)
	{
		if (ft_strchr(s_recip[fd], '\n'))
			break ;
		r_recip = malloc(BUFFER_SIZE + 1);
		if (!r_recip)
			return (NULL);
		bytes_read = read(fd, r_recip, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(r_recip), free(s_recip[fd]), s_recip[fd] = NULL, NULL);
		r_recip[bytes_read] = '\0';
		s_recip[fd] = extract_line(&s_recip[fd], &r_recip);
		free(r_recip);
	}
	final_line = next_and_free(&s_recip[fd], bytes_read);
	if (s_recip[fd] && *s_recip[fd] == 0)
		return (free(s_recip[fd]), s_recip[fd] = NULL, final_line);
	return (final_line);
}
