/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symbols.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 23:18:59 by student           #+#    #+#             */
/*   Updated: 2020/08/22 23:19:12 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width_star(const char **str, va_list args)
{
	if (**str == '*')
	{
		s.width = va_arg(args, int);
		if (s.width < 0)
		{
			s.minus = 1;
			s.width *= -1;
			s.symbol = ' ';
			s.zero = 0;
		}
		*str += 1;
	}
}

void	check_width(const char **str)
{
	if (ft_isdigit(**str))
	{
		s.width = ft_atoi(*str);
		*str += get_figures(s.width);
	}
}

void	check_precision(const char **str)
{
	if (**str == '.')
	{
		s.is_precision = 1;
		*str += 1;
		s.precision = ft_atoi(*str);
		while (**str == '0')
			*str += 1;
		if (ft_isdigit(**str))
			*str += get_figures(s.precision);
	}
}

void	check_precision_star(const char **str, va_list args)
{
	if (**str == '*')
	{
		s.precision = va_arg(args, int);
		if (s.precision < 0)
		{
			s.minus_precision = 1;
			s.precision *= -1;
		}
		*str += 1;
	}
}
