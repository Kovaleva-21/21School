/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 23:16:06 by student           #+#    #+#             */
/*   Updated: 2020/08/22 23:16:42 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_code_putaddr(long int div, unsigned long n, char temp, int fd)
{
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			write(fd, &temp, 1);
		}
		else
			write(fd, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void	ft_putaddr_fd(void *str, int fd)
{
	long int			div;
	char				temp;
	unsigned long int	n;

	temp = '0';
	n = (unsigned long int)str;
	div = 16;
	write(fd, "0x", 2);
	if (n < 10)
	{
		temp = '0' + n;
		write(1, &temp, 1);
	}
	else if (n < 16)
	{
		temp = '0' + n;
		temp += 39;
		write(1, &temp, 1);
	}
	else
		add_code_putaddr(div, n, temp, fd);
}

void	add_code_puthex(long int div, char temp, long long int n, int x)
{
	div = 16;
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			if (x == 'x')
				temp += 39;
			if (x == 'X')
				temp += 7;
			write(1, &temp, 1);
		}
		else
			write(1, &temp, 1);
		n %= div;
		div /= 16;
	}
}

void	ft_puthex_fd(long long int n, int x)
{
	long int	div;
	char		temp;

	temp = '0';
	div = 0;
	if (n < 10)
	{
		temp = '0' + n;
		write(1, &temp, 1);
	}
	else if (n < 16)
	{
		temp = '0' + n;
		if (x == 'x')
			temp += 39;
		if (x == 'X')
			temp += 7;
		write(1, &temp, 1);
	}
	else
		add_code_puthex(div, temp, n, x);
}

void	ft_putuns_fd(long long int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putuns_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}
