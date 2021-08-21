/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:25:09 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/27 17:26:35 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	unsigned char	sym;
	size_t			i;

	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	sym = c;
	i = 0;
	while (n > i)
	{
		ptr1[i] = ptr2[i];
		i++;
		if (ptr1[i - 1] == sym)
		{
			return (&dst[i]);
		}
	}
	return (NULL);
}
