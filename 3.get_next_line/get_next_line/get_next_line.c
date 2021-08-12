/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 23:57:10 by student           #+#    #+#             */
/*   Updated: 2020/08/04 01:13:29 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_remainder(char **remainder, char **line)
{
	char	*rem;

	rem = NULL;
	if (*remainder)
		if ((rem = ft_strchr(*remainder, '\n')))
		{
			*rem = '\0';
			*line = ft_strdup(*remainder);
			rem++;
			ft_strlcpy(*remainder, rem, BUFFER_SIZE);
		}
		else
		{
			*line = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	else
		*line = ft_strdup("\0");
	return (rem);
}

static char	*ft_joinfree(char *line, char *buf)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(tmp, buf);
	free(tmp);
	tmp = NULL;
	return (line);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int			x;
	char		*rem;
	static char	*remainder;

	if (line == NULL || BUFFER_SIZE < 1 || (read(fd, buf, 0) < 0))
		return (-1);
	rem = ft_remainder(&remainder, line);
	x = 1;
	while (!rem && (x = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[x] = '\0';
		if ((rem = ft_strchr(buf, '\n')))
		{
			*rem = '\0';
			remainder = ft_strdup(++rem);
		}
		if ((*line = ft_joinfree(*line, buf)) == NULL)
			return (-1);
	}
	return ((x == 0) ? 0 : 1);
}
