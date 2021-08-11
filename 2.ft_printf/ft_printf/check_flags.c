/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 23:17:41 by student           #+#    #+#             */
/*   Updated: 2020/08/22 23:18:38 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_space(const char **str)
{
	if (**str == ' ')
	{
		s.printed_symbols += write(1, " ", 1);
		*str += 1;
	}
}

void	check_minus(const char **str)
{
	if (**str == '-')
	{
		s.minus = 1;
		*str += 1;
		while ((**str == '-' || **str == '0') && **str != '\0')
			*str += 1;
	}
}

void	check_zero(const char **str)
{
	if (**str == '0')
	{
		if (!s.minus)
		{
			s.zero = 1;
			s.symbol = '0';
			while (**str == '0')
				*str += 1;
			if (**str == '-')
			{
				s.zero = 0;
				s.symbol = '0';
				*str += 1;
				s.minus = 1;
				while ((**str == '-' || **str == '0') && **str != '\0')
					*str += 1;
			}
		}
		else
			*str += 1;
	}
}
