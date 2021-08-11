/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 20:44:03 by student           #+#    #+#             */
/*   Updated: 2020/08/22 20:44:06 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_proc(const char **str)
{
	*str += 1;
	if (s.width)
	{
		s.width--;
		if (s.minus)
		{
			s.printed_symbols += write(1, "%", 1);
			s.symbol = ' ';
			ft_putsyms(s.symbol);
		}
		else
		{
			ft_putsyms(s.symbol);
			s.printed_symbols += write(1, "%", 1);
		}
	}
	else
		s.printed_symbols += write(1, "%", 1);
}
