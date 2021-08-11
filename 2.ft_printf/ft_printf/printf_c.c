/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:40:44 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:41:09 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_c(const char **format, va_list args)
{
	*format += 1;
	s.specifier_d = va_arg(args, int);
	if (s.width)
	{
		s.width--;
		if (s.minus)
		{
			s.printed_symbols += write(1, &s.specifier_d, 1);
			ft_putsyms(s.symbol);
		}
		else
		{
			ft_putsyms(s.symbol);
			s.printed_symbols += write(1, &s.specifier_d, 1);
		}
	}
	else
		s.printed_symbols += write(1, &s.specifier_d, 1);
}
