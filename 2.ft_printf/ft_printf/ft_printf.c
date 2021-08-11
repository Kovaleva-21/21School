/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:33:33 by student           #+#    #+#             */
/*   Updated: 2020/08/22 23:43:43 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putsym(const char **str)
{
	write(1, *str, 1);
	s.printed_symbols++;
	*str += 1;
}

void	str_processor(const char **str, va_list args)
{
	if (**str == 'd' || **str == 'i')
		printf_d(str, args);
	else if (**str == 's')
		printf_s(str, args);
	else if (**str == 'p')
		printf_p(str, args);
	else if (**str == 'c')
		printf_c(str, args);
	else if (**str == 'u')
		printf_u(str, args);
	else if (**str == 'x' || **str == 'X')
		printf_x(str, args);
	else if (**str == '%')
		printf_proc(str);
}

void	str_parser(const char **str, va_list args)
{
	check_space(str);
	check_minus(str);
	check_zero(str);
	check_width_star(str, args);
	check_width(str);
	check_precision(str);
	check_precision_star(str, args);
}

void	init(void)
{
	s.symbol = ' ';
	s.minus = 0;
	s.zero = 0;
	s.precision = 0;
	s.p_precision = 0;
	s.is_precision = 0;
	s.width = 0;
	s.specifier_d = 0;
	s.specifier_s = NULL;
	s.specifier_p = NULL;
	s.specifier_u = 0;
	s.specifier_x = 0;
	s.hex_symbol = 'x';
	s.minus_precision = 0;
}

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list args;

	i = 0;
	s.printed_symbols = 0;
	init();
	if (str == NULL)
		return (-1);
	va_start(args, str);
	while (str[i] != '\0')
	{
		init();
		if (str[i] == '%')
		{
			str++;
			str_parser(&str, args);
			str_processor(&str, args);
		}
		else
			ft_putsym(&str);
	}
	va_end(args);
	return (s.printed_symbols);
}
