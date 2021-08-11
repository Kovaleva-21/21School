/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 23:51:08 by student           #+#    #+#             */
/*   Updated: 2020/08/22 23:51:15 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_figures(long long int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
		i = i * -1;
	while (i > 0)
	{
		count++;
		i = i / 10;
	}
	return (count);
}

int	get_adress(void *str)
{
	long int			div;
	unsigned long int	n;
	int					count;

	count = 2;
	if (str == NULL)
		return (3);
	n = (unsigned long int)str;
	div = 16;
	if (n < 16)
		return (3);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		n %= div;
		div /= 16;
		count++;
	}
	return (count);
}

int	get_hex(long long int n)
{
	long int	div;
	int			count;

	count = 0;
	div = 16;
	if (n < 16)
		return (1);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		n %= div;
		div /= 16;
		count++;
	}
	return (count);
}
