/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:46:48 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:46:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsyms(char symbol)
{
	while (s.width > 0)
	{
		s.printed_symbols += write(1, &symbol, 1);
		s.width--;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	unsigned char ch;

	ch = (unsigned char)c;
	write(fd, &ch, 1);
}
