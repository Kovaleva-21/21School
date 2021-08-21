/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:25:09 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/27 17:25:34 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_negativ(char *ptr, int i, int n)
{
	ptr[0] = '-';
	while (n != 0)
	{
		i--;
		ptr[i] = n % 10 * (-1) + '0';
		n = n / 10;
	}
	return (ptr);
}

static char		*ft_itoa_pozitiv(char *ptr, int i, int n)
{
	while (n != 0)
	{
		i--;
		ptr[i] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}

char			*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		m;

	i = 0;
	m = n;
	while (m != 0)
	{
		m = m / 10;
		i++;
	}
	if (n <= 0)
		i++;
	ptr = (char*)malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (n < 0)
		ptr = ft_itoa_negativ(ptr, i, n);
	else if (n == 0)
		ptr[0] = '0';
	else
		ptr = ft_itoa_pozitiv(ptr, i, n);
	return (ptr);
}
