/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ceilling_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:27:58 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/24 23:06:19 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		pars_ceilling_color2(t_color *color, t_vars *vars, char *str)
{
	if (ft_isdigit(str[color->count_str]))
	{
		color->flag = (ft_atoi(&str[color->count_str]));
		if (color->flag < 0 || color->flag > 255)
		{
			ft_putstr_fd("Error\nceiling color error\n", 2);
			exit(0);
		}
		color->count_str += ft_strlen((color->ptr = ft_itoa(color->flag)));
		free(color->ptr);
		vars->color_c = (color->flag << 16);
	}
	else
	{
		ft_putstr_fd("Error\nceiling color error\n", 2);
		exit(0);
	}
	if (str[color->count_str] == ',')
		color->count_str++;
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

static void		pars_ceilling_color3(t_color *color, t_vars *vars, char *str)
{
	while (str[color->count_str] == ' ')
		color->count_str++;
	if (ft_isdigit(str[color->count_str]))
	{
		color->flag = (ft_atoi(&str[color->count_str]));
		if (color->flag < 0 || color->flag > 255)
		{
			ft_putstr_fd("Error\nceiling color error\n", 2);
			exit(0);
		}
		color->count_str += ft_strlen((color->ptr = ft_itoa(color->flag)));
		free(color->ptr);
		vars->color_c += (color->flag << 8);
	}
	else
	{
		ft_putstr_fd("Error\nceiling color error\n", 2);
		exit(0);
	}
	while (str[color->count_str] == ' ')
		color->count_str++;
}

static void		pars_ceilling_color4(t_color *color, t_vars *vars, char *str)
{
	while (str[color->count_str] == ' ')
		color->count_str++;
	if (ft_isdigit(str[color->count_str]))
	{
		color->flag = (ft_atoi(&str[color->count_str]));
		if (color->flag < 0 || color->flag > 255)
		{
			ft_putstr_fd("Error\nceiling color error\n", 2);
			exit(0);
		}
		color->count_str += ft_strlen((color->ptr = ft_itoa(color->flag)));
		free(color->ptr);
		vars->color_c += color->flag;
	}
	else
	{
		ft_putstr_fd("Error\nceiling color error\n", 2);
		exit(0);
	}
	if (str[color->count_str] != ' ' && str[color->count_str] != '\0')
	{
		ft_putstr_fd("Error\nceiling color error\n", 2);
		exit(0);
	}
}

static void		pars_ceilling_color5(t_color *color, char *str)
{
	if (str[color->count_str] == ',')
		color->count_str++;
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

int				pars_ceilling_color(t_vars *vars, char *str)
{
	t_color color;

	init_color(&color);
	while (str[color.count_str] != '\0')
	{
		if (str[color.count_str] == ' ')
		{
			color.count_str++;
			continue;
		}
		pars_ceilling_color2(&color, vars, str);
		while (str[color.count_str] == ' ')
			color.count_str++;
		pars_ceilling_color3(&color, vars, str);
		pars_ceilling_color5(&color, str);
		pars_ceilling_color4(&color, vars, str);
		if (str[color.count_str] == ' ')
		{
			color.count_str++;
			continue;
		}
	}
	return (0);
}
