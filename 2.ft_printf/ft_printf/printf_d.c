/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:42:33 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:42:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr_countsym(void)
{
	ft_putnbr_fd(s.specifier_d, 1);
	s.printed_symbols += get_figures(s.specifier_d);
}

void	spec_d_dop(void)
{
	if (s.is_precision)
	{
		if (s.specifier_d < 0 && s.specifier_d != -2147483648)
		{
			write(1, "-", 1);
			s.specifier_d *= -1;
		}
		while (s.precision > get_figures(s.specifier_d))
		{
			s.printed_symbols += write(1, "0", 1);
			s.precision--;
			s.p_precision++;
		}
		if (s.specifier_d != 0 || s.precision != 0 || s.is_precision != 1)
			putnbr_countsym();
		s.width -= s.p_precision;
		ft_putsyms(' ');
	}
	else
	{
		putnbr_countsym();
		ft_putsyms(s.symbol);
	}
}

void	spec_d_dop2(void)
{
	if (s.specifier_d < 0 && s.width <= 0)
	{
		write(1, "-", 1);
		s.specifier_d *= -1;
	}
	if (s.precision > 0)
		s.width = s.width - s.precision + get_figures(s.specifier_d);
	ft_putsyms(' ');
	if (s.specifier_d < 0)
	{
		write(1, "-", 1);
		s.specifier_d *= -1;
	}
	while (s.precision > get_figures(s.specifier_d))
	{
		s.printed_symbols += write(1, "0", 1);
		s.precision--;
	}
	putnbr_countsym();
}

void	spec_d_dop3(void)
{
	if (s.specifier_d < 0)
		s.width--;
	if (s.minus)
		spec_d_dop();
	else
	{
		if (s.is_precision && (s.precision - get_figures(s.specifier_d) > 0))
			spec_d_dop2();
		else
		{
			if (s.specifier_d < 0 && s.zero &&
				(s.is_precision != 1) && s.specifier_d != -2147483648)
			{
				write(1, "-", 1);
				s.specifier_d *= -1;
			}
			if (s.is_precision)
				s.symbol = ' ';
			ft_putsyms(s.symbol);
			if (s.specifier_d != 0 || s.precision != 0 || s.is_precision != 1)
				putnbr_countsym();
		}
	}
}

void	printf_d(const char **str, va_list args)
{
	*str += 1;
	s.specifier_d = va_arg(args, int);
	if (s.minus_precision == 1)
		s.is_precision = 0;
	if (s.specifier_d < 0)
		s.printed_symbols++;
	if (s.width || s.is_precision)
	{
		if (s.specifier_d == 0 && s.precision == 0 &&
				s.is_precision == 1 && s.width > 0)
			s.width++;
		s.width -= get_figures(s.specifier_d);
		spec_d_dop3();
	}
	else
		putnbr_countsym();
}
