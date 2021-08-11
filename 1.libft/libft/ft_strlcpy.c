/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 23:08:03 by student           #+#    #+#             */
/*   Updated: 2020/05/31 03:57:06 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
