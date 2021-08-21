/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:14:07 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 20:19:22 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		valid_res_text(t_valid *valid, t_vars *vars)
{
	if (vars->mas[valid->count_str][valid->count_mas] == 'R')
	{
		pars_skrin_size(vars, &vars->mas[valid->count_str][valid->count_mas]);
		valid->flag_mas[0]++;
		return (1);
	}
	else if (vars->mas[valid->count_str][valid->count_mas] == 'N'
	&& vars->mas[valid->count_str][valid->count_mas + 1] == 'O')
	{
		pars_texture(vars, "NO", &vars->text.addr_n,
		&vars->mas[valid->count_str][valid->count_mas + 2]);
		valid->flag_mas[1]++;
		return (1);
	}
	else if (vars->mas[valid->count_str][valid->count_mas] == 'S'
	&& vars->mas[valid->count_str][valid->count_mas + 1] == 'O')
	{
		pars_texture(vars, "SO", &vars->text.addr_s,
		&vars->mas[valid->count_str][valid->count_mas + 2]);
		valid->flag_mas[2]++;
		return (1);
	}
	return (0);
}

int		valid_textures_res(t_valid *valid, t_vars *vars)
{
	pars_texture(vars, "S", &vars->text.addr_spr,
	&vars->mas[valid->count_str][valid->count_mas + 1]);
	valid->flag_mas[5]++;
	return (1);
}

int		valid_textures(t_valid *valid, t_vars *vars)
{
	if (vars->mas[valid->count_str][valid->count_mas] == 'W'
	&& vars->mas[valid->count_str][valid->count_mas + 1] == 'E')
	{
		pars_texture(vars, "WE", &vars->text.addr_w,
		&vars->mas[valid->count_str][valid->count_mas + 2]);
		valid->flag_mas[3]++;
		return (1);
	}
	else if (vars->mas[valid->count_str][valid->count_mas] == 'E'
	&& vars->mas[valid->count_str][valid->count_mas + 1] == 'A')
	{
		pars_texture(vars, "EA", &vars->text.addr_e,
		&vars->mas[valid->count_str][valid->count_mas + 2]);
		valid->flag_mas[4]++;
		return (1);
	}
	else if (vars->mas[valid->count_str][valid->count_mas] == 'S'
	&& (vars->mas[valid->count_str][valid->count_mas + 1] == ' '
	|| vars->mas[valid->count_str][valid->count_mas + 1] == '.'))
	{
		if (valid_textures_res(valid, vars) == 1)
			return (1);
	}
	return (0);
}

int		valid_flor_res(t_valid *valid, t_vars *vars)
{
	pars_ceilling_color(vars,
	&vars->mas[valid->count_str][valid->count_mas + 1]);
	valid->flag_mas[7]++;
	return (1);
}

int		valid_flor(t_valid *valid, t_vars *vars)
{
	if (vars->mas[valid->count_str][valid->count_mas] == 'F'
	&& (vars->mas[valid->count_str][valid->count_mas + 1] == ' '
	|| ft_isdigit(vars->mas[valid->count_str][valid->count_mas + 1])))
	{
		pars_flor_color(vars,
		&vars->mas[valid->count_str][valid->count_mas + 1]);
		valid->flag_mas[6]++;
		return (1);
	}
	else if (vars->mas[valid->count_str][valid->count_mas] == 'C'
	&& (vars->mas[valid->count_str][valid->count_mas + 1] == ' '
	|| ft_isdigit(vars->mas[valid->count_str][valid->count_mas + 1])))
	{
		if (valid_flor_res(valid, vars) == 1)
			return (1);
	}
	else if (vars->mas[valid->count_str][valid->count_mas] != ' '
	&& vars->mas[valid->count_str][valid->count_mas] != '1'
	&& vars->mas[valid->count_str][valid->count_mas] != '\0')
	{
		ft_putstr_fd("Error\nerror in resource files\n", 2);
		exit(0);
	}
	return (0);
}
