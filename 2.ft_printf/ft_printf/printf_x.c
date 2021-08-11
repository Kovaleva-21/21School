/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:46:48 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:46:52 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthex_countsym(void)
{
	ft_puthex_fd(s.specifier_x, s.hex_symbol);
	s.printed_symbols += get_hex(s.specifier_x);
}

void	spec_x_dop(void)
{
	if (s.is_precision)
	{
		while (s.precision > get_hex(s.specifier_x))
		{
			s.printed_symbols += write(1, "0", 1);
			s.precision--;
			s.p_precision++;
		}
		if (s.specifier_x != 0 || s.precision != 0 || s.is_precision != 1)
			puthex_countsym();
		s.width -= s.p_precision;
		ft_putsyms(' ');
	}
	else
	{
		puthex_countsym();
		ft_putsyms(s.symbol);
	}
}

void	spec_x_dop2(void)
{
	if ((s.precision - get_hex(s.specifier_x)) > 0)
		s.width = s.width - s.precision + get_hex(s.specifier_x);
	if (s.minus_precision == 1)
		ft_putsyms(s.symbol);
	else
		while (s.width > 0)
		{
			s.printed_symbols += write(1, " ", 1);
			s.width--;
		}
	while (s.precision > get_hex(s.specifier_x))
	{
		s.printed_symbols += write(1, "0", 1);
		s.precision--;
	}
	if (s.specifier_x != 0 || s.precision != 0 || s.is_precision != 1)
		puthex_countsym();
}

void	spec_x_dop3(void)
{
	if (s.specifier_x == 0 && s.precision == 0 &&
		s.is_precision == 1 && s.width > 0)
		s.width++;
	s.width -= get_hex(s.specifier_x);
	if (s.minus)
		spec_x_dop();
	else
	{
		if (s.is_precision)
			spec_x_dop2();
		else
		{
			ft_putsyms(s.symbol);
			puthex_countsym();
		}
	}
}

void	printf_x(const char **str, va_list args)
{
	if (**str == 'X')
		s.hex_symbol = 'X';
	*str += 1;
	s.specifier_x = va_arg(args, unsigned int);
	if (s.width || s.is_precision)
		spec_x_dop3();
	else
		puthex_countsym();
}
