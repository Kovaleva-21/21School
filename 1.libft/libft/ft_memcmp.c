/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 00:51:33 by student           #+#    #+#             */
/*   Updated: 2020/05/26 03:56:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;

	arr1 = (unsigned char*)s1;
	arr2 = (unsigned char*)s2;
	i = 0;
	if (arr1 == arr2 || n == 0)
		return (0);
	while (i < n && arr1[i] == arr2[i])
		i++;
	if (i == n)
		return (0);
	return (arr1[i] - arr2[i]);
}
