/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:59:15 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 20:13:56 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_valid(t_valid *valid)
{
	int i;

	i = 0;
	valid->count_mas = 0;
	valid->count_str = 0;
	valid->i = 0;
	valid->flag_start = 0;
	while (i < 10)
	{
		valid->flag_mas[i] = 0;
		i++;
	}
}

static void		valid_mup_cub2(t_valid *valid, t_vars *vars)
{
	while (vars->mas[valid->count_str][valid->count_mas] != '\0')
	{
		if ((ft_strchr("120WSNE ", vars->mas[valid->count_str]
		[valid->count_mas])) == NULL)
		{
			ft_putstr_fd("Error\nerror in resource files\n", 2);
			exit(0);
		}
		if ((ft_strchr("120WSNE", vars->mas[valid->count_str]
		[valid->count_mas])) != NULL && valid->flag_mas[9] == 0)
		{
			valid->flag_mas[9]++;
			valid_mup(vars, valid->count_str, valid->count_mas);
		}
		if ((ft_strchr("WSNE", vars->mas[valid->count_str]
		[valid->count_mas])) != NULL)
			valid->flag_mas[8]++;
		valid->count_mas++;
	}
	valid->count_mas = 0;
}

static int		valid_mups(t_valid *valid, t_vars *vars)
{
	if (vars->mas[valid->count_str][valid->count_mas] == '1')
	{
		valid->i = valid->count_mas;
		if (valid->flag_start == 0)
		{
			while (vars->mas[valid->count_str][valid->i] != '\0')
			{
				if ((ft_strchr("20WSNE ", vars->mas[valid->count_str]
				[valid->i])) != NULL)
				{
					ft_putstr_fd("Error\nerror in map\n", 2);
					exit(0);
				}
				valid->flag_start = 1;
				valid->i++;
			}
		}
		valid_mup_cub2(valid, vars);
	}
	return (0);
}

static void		valid_mup_cub3(t_valid *valid, t_vars *vars)
{
	while (vars->mas[valid->count_str] != NULL)
	{
		while (vars->mas[valid->count_str][valid->count_mas] ==
		' ' && vars->mas[valid->count_str][valid->count_mas] != '\0')
			valid->count_mas++;
		if (valid_res_text(valid, vars) == 1)
		{
		}
		else if (valid_textures(valid, vars) == 1)
		{
		}
		else if (valid_flor(valid, vars) == 1)
		{
		}
		else if (valid_mups(valid, vars) == 1)
		{
		}
		valid->count_mas = 0;
		valid->count_str++;
	}
	valid->count_mas = 0;
}

void			valid_mup_cub(t_vars *vars)
{
	t_valid valid;

	init_valid(&valid);
	valid_mup_cub3(&valid, vars);
	while (valid.count_mas < 10)
	{
		if (valid.flag_mas[valid.count_mas] != 1)
		{
			ft_putstr_fd("Error\nerror in resource files\n", 2);
			exit(0);
		}
		valid.count_mas++;
	}
}
