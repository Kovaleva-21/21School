/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 01:05:53 by student           #+#    #+#             */
/*   Updated: 2020/05/27 14:51:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s, const char *p, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i] && i < size)
		i++;
	while (p[j] && (i + j + 1) < size)
	{
		s[i + j] = p[j];
		j++;
	}
	if (i < size)
		s[i + j] = '\0';
	return (i + ft_strlen(p));
}
