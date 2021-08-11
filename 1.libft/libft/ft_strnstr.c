/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:13:07 by student           #+#    #+#             */
/*   Updated: 2020/05/30 01:33:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *p, size_t n)
{
	size_t	len;

	len = ft_strlen(p);
	if (!*p)
		return ((char *)s);
	while (*s && n-- >= len)
	{
		if (*s == *p && ft_memcmp(s, p, len) == 0)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
