/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:44:45 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:46:03 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_s_dop3(void)
{
	if (s.precision == 0)
		s.width += ft_strlen(s.specifier_s);
	if (s.precision > 0 && (s.precision < ft_strlen(s.specifier_s)))
		s.width = s.width - s.precision + ft_strlen(s.specifier_s);
	ft_putsyms(' ');
	while (s.precision > ft_strlen(s.specifier_s))
		s.precision--;
	if (s.precision > 0)
	{
		while (s.precision > 0)
		{
			s.printed_symbols += write(1, s.specifier_s++, 1);
			s.precision--;
		}
	}
}

void	spec_s_dop2(void)
{
	if (s.precision == 0)
		s.width += ft_strlen(s.specifier_s);
	if (s.precision > 0 && (s.precision < ft_strlen(s.specifier_s)))
		s.width = s.width - s.precision + ft_strlen(s.specifier_s);
	while (s.precision > ft_strlen(s.specifier_s))
		s.precision--;
	if (s.precision > 0)
	{
		while (s.precision > 0)
		{
			s.printed_symbols += write(1, s.specifier_s++, 1);
			s.precision--;
		}
	}
	ft_putsyms(' ');
}

void	spec_s_dop(void)
{
	s.width -= ft_strlen(s.specifier_s);
	if (s.minus)
	{
		if (s.is_precision)
			spec_s_dop2();
		else
		{
			ft_putstr_fd(s.specifier_s, 1);
			s.printed_symbols += ft_strlen(s.specifier_s);
			ft_putsyms(s.symbol);
		}
	}
	else
	{
		if (s.is_precision)
			spec_s_dop3();
		else
		{
			ft_putsyms(s.symbol);
			ft_putstr_fd(s.specifier_s, 1);
			s.printed_symbols += ft_strlen(s.specifier_s);
		}
	}
}

void	printf_s(const char **str, va_list args)
{
	*str += 1;
	s.specifier_s = va_arg(args, char *);
	if (s.specifier_s == NULL)
		s.specifier_s = "(null)";
	if (s.minus_precision == 1)
		s.is_precision = 0;
	if (s.width || s.is_precision)
		spec_s_dop();
	else
	{
		if (s.specifier_s != NULL)
		{
			ft_putstr_fd(s.specifier_s, 1);
			s.printed_symbols += ft_strlen(s.specifier_s);
		}
		else
		{
			ft_putstr_fd("(null)", 1);
			s.printed_symbols += ft_strlen("(null)");
		}
	}
}
