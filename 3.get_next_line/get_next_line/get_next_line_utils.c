/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:03:31 by student           #+#    #+#             */
/*   Updated: 2020/08/03 23:19:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)s;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*j;

	i = 0;
	j = (char *)malloc(sizeof(*j) * ft_strlen(src) + 1);
	if (j == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		j[i] = src[i];
		i++;
	}
	j[i] = '\0';
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = (ft_strlen(s1) + ft_strlen(s2));
	join = (char*)malloc(sizeof(char) * len + 1);
	if (!join)
		return (NULL);
	while (s1[j] != '\0')
		join[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

size_t	ft_strlcpy(char *s, const char *p, size_t size)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	if (size == 0)
		return (ft_strlen(p));
	while (p[i] != '\0' && i < size - 1)
	{
		s[i] = p[i];
		i++;
	}
	s[i] = '\0';
	return (ft_strlen(p));
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
