/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:43:00 by student           #+#    #+#             */
/*   Updated: 2020/08/22 23:48:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

struct	s_variables
{
	int				printed_symbols;
	int				width;
	int				precision;
	int				specifier_d;
	char			*specifier_s;
	void			*specifier_p;
	unsigned int	specifier_u;
	unsigned int	specifier_x;
	int				minus;
	int				zero;
	int				minus_precision;
	int				is_precision;
	int				p_precision;
	char			hex_symbol;
	char			symbol;
}					s;

int		ft_printf(const char *format, ...);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		get_adress(void *str);
int		get_hex(long long int n);
int		get_figures(long long int i);
void	add_code_putaddr(long int div, unsigned long n, char temp, int fd);
void	add_code_puthex(long int div, char temp, long long int n, int x);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putuns_fd(long long int n, int fd);
void	ft_putaddr_fd(void *str, int fd);
void	ft_puthex_fd(long long int n, int x);
void	ft_putsyms(char symbol);
void	ft_putsym(const char **format);

void	init(void);
void	check_space(const char **format);
void	check_minus(const char **format);
void	check_zero(const char **format);
void	check_width_star(const char **format, va_list args);
void	check_width(const char **format);
void	check_precision(const char **format);
void	check_precision_star(const char **format, va_list args);
void	printf_d(const char **format, va_list args);
void	printf_s(const char **format, va_list args);
void	printf_p(const char **format, va_list args);
void	printf_c(const char **format, va_list args);
void	printf_u(const char **format, va_list args);
void	printf_x(const char **format, va_list args);
void	printf_proc(const char **format);
void	format_parser(const char **format, va_list args);
void	format_processor(const char **format, va_list args);

#endif
