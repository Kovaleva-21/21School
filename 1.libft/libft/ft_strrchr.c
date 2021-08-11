/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:45:21 by student           #+#    #+#             */
/*   Updated: 2020/05/27 14:12:00 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		s_len;

	str = NULL;
	s_len = ft_strlen(s);
	if (c == 0)
		return ((char*)s + s_len);
	while (*s)
	{
		if (*s == (char)c)
			str = (char*)s;
		s++;
	}
	return (str);
}
