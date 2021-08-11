/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 02:30:34 by student           #+#    #+#             */
/*   Updated: 2020/05/28 00:59:36 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s, const void *p, size_t n)
{
	char		*arr;
	const char	*str;
	size_t		i;

	arr = s;
	str = p;
	i = 0;
	if (s == 0 && p == 0)
		return (s);
	if (str <= arr)
	{
		while (n--)
			arr[n] = str[n];
	}
	else
	{
		while (i < n)
		{
			arr[i] = str[i];
			i++;
		}
	}
	return (s);
}
