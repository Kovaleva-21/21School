/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoliss <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:46:26 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:46:28 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putuns_countsym(void)
{
	ft_putuns_fd(s.specifier_u, 1);
	s.printed_symbols += get_figures(s.specifier_u);
}

void	spec_u_dop(void)
{
	if (s.is_precision)
	{
		while (s.precision > get_figures(s.specifier_u))
		{
			s.printed_symbols += write(1, "0", 1);
			s.precision--;
			s.p_precision++;
		}
		if (s.specifier_u != 0 || s.precision != 0 || s.is_precision != 1)
			putuns_countsym();
		ft_putsyms(' ');
	}
	else
	{
		putuns_countsym();
		ft_putsyms(s.symbol);
	}
}

void	spec_u_dop2(void)
{
	if (s.is_precision)
	{
		if (s.minus_precision == 1)
			ft_putsyms(s.symbol);
		else
			ft_putsyms(' ');
		while (s.precision > get_figures(s.specifier_u))
		{
			s.printed_symbols += write(1, "0", 1);
			s.precision--;
		}
		if (s.specifier_u != 0 || s.precision != 0 || s.is_precision != 1)
			putuns_countsym();
	}
	else
	{
		ft_putsyms(s.symbol);
		putuns_countsym();
	}
}

void	printf_u(const char **str, va_list args)
{
	*str += 1;
	s.specifier_u = va_arg(args, long long int);
	if (s.width || s.is_precision)
	{
		if (s.specifier_u == 0 && s.precision == 0 &&
			s.is_precision == 1 && s.width > 0)
			s.width++;
		if ((s.precision - get_figures(s.specifier_u)) > 0)
			s.width = s.width - s.precision;
		else
			s.width -= get_figures(s.specifier_u);
		if (s.minus)
			spec_u_dop();
		else
			spec_u_dop2();
	}
	else
		putuns_countsym();
}
