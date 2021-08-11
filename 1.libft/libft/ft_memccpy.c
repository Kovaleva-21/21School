/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 18:08:37 by student           #+#    #+#             */
/*   Updated: 2020/05/20 02:27:37 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s, const void *p, int c, size_t n)
{
	char		*arr;
	const char	*str;
	char		cod;
	size_t		i;

	arr = s;
	str = p;
	cod = c;
	i = 0;
	while (n > i)
	{
		arr[i] = str[i];
		if (str[i] == cod)
			return (s + 1 + i);
		i++;
	}
	return (NULL);
}
