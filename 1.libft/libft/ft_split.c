/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 23:22:44 by student           #+#    #+#             */
/*   Updated: 2020/05/31 11:42:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int		words_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void		*leak(char **split, int w)
{
	int	i;

	i = 0;
	while (i < w)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static char		**fill(char const *s, int w, char c, char **split)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < w)
	{
		while (*s == c)
			s++;
		len = words_len(s, c);
		if (!(split[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (leak(split, i));
		j = 0;
		while (j < len)
		{
			split[i][j] = *s;
			j++;
			s++;
		}
		split[i][j] = '\0';
	}
	split[i] = NULL;
	return (split);
}

char			**ft_split(char	const *s, char c)
{
	char	**split;
	int		w;

	if (!s)
		return (NULL);
	w = count_words(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (w + 1))))
		return (NULL);
	split = fill(s, w, c, split);
	return (split);
}
