/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:29:34 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/27 17:29:38 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		funk_for_free_dup(char **ptr, char *ptr2)
{
	char	*ptr_for_free;

	ptr_for_free = *ptr;
	*ptr = ft_strdup(ptr2);
	free(ptr_for_free);
	if (!ptr)
		return (-1);
	return (0);
}

int		funk_for_free_join(char **ptr, char *ptr2)
{
	char	*ptr_for_free;

	ptr_for_free = *ptr;
	*ptr = ft_strjoin(*ptr, ptr2);
	free(ptr_for_free);
	if (!ptr)
		return (-1);
	return (0);
}

int		gnl_static(char **ptr_static, char **line, char **ptr)
{
	if ((*ptr = (ft_strchr(*ptr_static, '\n'))))
	{
		**ptr = '\0';
		if (funk_for_free_join(&*line, *ptr_static) == -1)
			return (-1);
		(*ptr)++;
		if (funk_for_free_dup(&*ptr_static, *ptr) == -1)
			return (-1);
	}
	else
	{
		if (funk_for_free_join(&*line, *ptr_static) == -1)
			return (-1);
		funk_for_free_dup(&*ptr_static, "\0");
	}
	return (0);
}

int		gnl_read(int fd, char **ptr_static, char **line, char **ptr)
{
	char	*buf;
	int		i;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!*ptr && ((i = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[i] = '\0';
		if ((*ptr = ft_strchr(buf, '\n')))
		{
			**ptr = '\0';
			(*ptr)++;
			if (funk_for_free_dup(&*ptr_static, *ptr) == -1)
				return (-1);
		}
		if (funk_for_free_join(&*line, buf) == -1)
			return (-1);
	}
	free(buf);
	if (i > 1 || *ptr != NULL)
		return (0);
	return (i == 0 ? 1 : -1);
}

int		get_next_line(int fd, char **line)
{
	char		*ptr;
	static char	*ptr_static;
	int			flag;

	ptr = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	*line = ft_strdup("");
	if (ptr_static)
		if ((flag = gnl_static(&ptr_static, &*line, &ptr)) == -1)
			return (-1);
	if (!ptr)
		if ((flag = gnl_read(fd, &ptr_static, &*line, &ptr)) == -1)
			return (-1);
	if (ptr != NULL || flag == 0)
		return (1);
	else
	{
		if (ptr_static)
		{
			free(ptr_static);
			ptr_static = NULL;
		}
		return (0);
	}
}
