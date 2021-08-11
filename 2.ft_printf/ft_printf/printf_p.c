/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:43:28 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:43:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putaddr_countsym(void)
{
	ft_putaddr_fd(s.specifier_p, 1);
	s.printed_symbols += get_adress(s.specifier_p);
}

void	spec_p_dop(void)
{
	s.width -= 2;
	if (s.minus)
	{
		s.printed_symbols += write(1, "0x", 2);
		ft_putsyms(s.symbol);
	}
	else
	{
		ft_putsyms(s.symbol);
		s.printed_symbols += write(1, "0x", 2);
	}
}

void	spec_p_dop2(void)
{
	s.width -= get_adress(s.specifier_p);
	if (s.minus)
	{
		putaddr_countsym();
		ft_putsyms(s.symbol);
	}
	else
	{
		ft_putsyms(s.symbol);
		putaddr_countsym();
	}
}

void	printf_p(const char **format, va_list args)
{
	*format += 1;
	s.specifier_p = va_arg(args, void *);
	if (s.width)
	{
		if (s.precision == 0 && s.is_precision == 1)
			spec_p_dop();
		else
			spec_p_dop2();
	}
	else
	{
		if (s.precision == 0 && s.is_precision == 1)
			s.printed_symbols += write(1, "0x", 2);
		else
			putaddr_countsym();
	}
}
