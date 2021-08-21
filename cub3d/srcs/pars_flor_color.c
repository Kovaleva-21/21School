/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_flor_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:43:25 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/24 14:45:27 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	pars_flor_color2(t_flor *flor, t_vars *vars, char *str)
{
	if (ft_isdigit(str[flor->count_str]))
	{
		flor->flag = (ft_atoi(&str[flor->count_str]));
		if (flor->flag < 0 || flor->flag > 255)
		{
			ft_putstr_fd("Error\nflor color error\n", 2);
			exit(0);
		}
		flor->count_str += ft_strlen((flor->ptr = ft_itoa(flor->flag)));
		free(flor->ptr);
		vars->color_f += (flor->flag << 8);
	}
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
	if (str[flor->count_str] == ',')
		flor->count_str++;
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

static void	pars_flor_color3(t_flor *flor, t_vars *vars, char *str)
{
	if (ft_isdigit(str[flor->count_str]))
	{
		flor->flag = (ft_atoi(&str[flor->count_str]));
		if (flor->flag < 0 || flor->flag > 255)
		{
			ft_putstr_fd("Error\nflor color error\n", 2);
			exit(0);
		}
		flor->count_str += ft_strlen((flor->ptr = ft_itoa(flor->flag)));
		free(flor->ptr);
		vars->color_f = (flor->flag << 16);
	}
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
	while (str[flor->count_str] == ' ')
		flor->count_str++;
}

static void	pars_flor_color4(t_flor *flor, t_vars *vars, char *str)
{
	while (str[flor->count_str] == ' ')
		flor->count_str++;
	pars_flor_color2(flor, vars, str);
	while (str[flor->count_str] == ' ')
		flor->count_str++;
	while (str[flor->count_str] == ' ')
		flor->count_str++;
	if (ft_isdigit(str[flor->count_str]))
	{
		flor->flag = (ft_atoi(&str[flor->count_str]));
		if (flor->flag < 0 || flor->flag > 255)
		{
			ft_putstr_fd("Error\nflor color error\n", 2);
			exit(0);
		}
		flor->count_str += ft_strlen((flor->ptr = ft_itoa(flor->flag)));
		free(flor->ptr);
		vars->color_f += flor->flag;
	}
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

static void	pars_flor_color5(t_flor *flor, char *str)
{
	if (str[flor->count_str] == ',')
		flor->count_str++;
	else
	{
		ft_putstr_fd("Error\nflor color error\n", 2);
		exit(0);
	}
}

int			pars_flor_color(t_vars *vars, char *str)
{
	t_flor flor;

	init_flor(&flor);
	while (str[flor.count_str] != '\0')
	{
		if (str[flor.count_str] == ' ')
		{
			flor.count_str++;
			continue;
		}
		pars_flor_color3(&flor, vars, str);
		pars_flor_color5(&flor, str);
		pars_flor_color4(&flor, vars, str);
		if (str[flor.count_str] == ' ')
		{
			flor.count_str++;
			continue;
		}
		if (str[flor.count_str] != ' ' && str[flor.count_str] != '\0')
		{
			ft_putstr_fd("Error\nflor color error\n", 2);
			exit(0);
		}
	}
	return (0);
}
