/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:25:09 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/27 17:27:53 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	m;

	i = 0;
	j = 0;
	m = ft_strlen(needle);
	if (m == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
			while (haystack[i] == needle[j] && i < len && haystack[i] != '\0')
			{
				i++;
				j++;
				if (j == m)
					return ((char *)&haystack[i - j]);
			}
		i = i - j;
		j = 0;
		i++;
	}
	return (NULL);
}
