/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:23:40 by student           #+#    #+#             */
/*   Updated: 2020/05/26 03:51:06 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	cod;

	i = 0;
	cod = c;
	arr = (unsigned char *)s;
	while (n > 0)
	{
		if (arr[i] == cod)
			return (&arr[i]);
		i++;
		n--;
	}
	return (NULL);
}
