/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 03:47:55 by student           #+#    #+#             */
/*   Updated: 2020/05/28 00:59:19 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s, const void *p, size_t n)
{
	char		*arr;
	const char	*str;

	arr = s;
	str = p;
	if (s == 0 && p == 0)
		return (s);
	while (n > 0)
	{
		n--;
		arr[n] = str[n];
	}
	return (s);
}
