/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rastoinie_dop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 20:33:43 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/26 22:13:08 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	count_rastoinie_res_3(t_rastoinie *rastoinie, char **mas)
{
	while (rastoinie->j < rastoinie->end_mas_y
	&& rastoinie->i >= 0 && rastoinie->j >= 0
	&& rastoinie->i <= (int)ft_strlen(mas[rastoinie->j])
	&& mas[rastoinie->j][rastoinie->i] != '1')
	{
		rastoinie->ax = rastoinie->ax + rastoinie->xa;
		rastoinie->ay = rastoinie->ay + rastoinie->ya;
		rastoinie->i = rastoinie->ax / 64;
		rastoinie->j = rastoinie->ay / 64;
	}
}

void	count_rastoinie_res_4(t_rastoinie *rastoinie, double pow)
{
	if ((pow < 2 * M_PI && pow > 3 * M_PI / 2 && pow != M_PI_2)
	|| (pow > 0 && pow < M_PI_2))
	{
		rastoinie->bx = (int)(rastoinie->px / 64) * 64 + 64;
		rastoinie->xa = 64;
		rastoinie->by = rastoinie->py + (rastoinie->px
		- rastoinie->bx) * tan(M_PI * 2 - pow);
		rastoinie->ya = 64 * tan(pow);
	}
	else if (pow == M_PI_2 || pow == 3 * M_PI / 2)
	{
		rastoinie->bx = rastoinie->px;
		rastoinie->xa = 64;
	}
	else
	{
		rastoinie->bx = (int)(rastoinie->px
		/ 64) * 64 - 0.000000001;
		rastoinie->xa = -64;
		rastoinie->by = rastoinie->py + (rastoinie->px
		- rastoinie->bx) * tan(M_PI * 2 - pow);
		rastoinie->ya = 64 * tan(M_PI * 2 - pow);
	}
}

void	count_rastoinie_res_5(t_rastoinie *rastoinie, char **mas)
{
	rastoinie->i1 = rastoinie->bx / 64;
	rastoinie->j1 = rastoinie->by / 64;
	while (rastoinie->j1 < rastoinie->end_mas_y
	&& rastoinie->i1 >= 0 && rastoinie->j1 >= 0
	&& rastoinie->i1 <= (int)ft_strlen(mas[rastoinie->j1])
	&& mas[rastoinie->j1][rastoinie->i1] != '1')
	{
		rastoinie->bx = rastoinie->bx + rastoinie->xa;
		rastoinie->by = rastoinie->by + rastoinie->ya;
		rastoinie->i1 = rastoinie->bx / 64;
		rastoinie->j1 = rastoinie->by / 64;
	}
	rastoinie->len_gor = sqrt((powf((rastoinie->px - rastoinie->ax), 2)
	+ powf((rastoinie->py - rastoinie->ay), 2)));
	rastoinie->len_ver = sqrt((powf((rastoinie->px - rastoinie->bx), 2)
	+ powf((rastoinie->py - rastoinie->by), 2)));
}

void	count_rastoinie_res_6(t_rastoinie *rastoinie, t_vars *vars, double pow)
{
	vars->flag_wall = 1;
	if (pow > M_PI)
	{
		vars->bx = (int)rastoinie->ax % 64 + (rastoinie->ax -
		(int)rastoinie->ax);
		vars->text.addr = vars->text.addr_n;
	}
	else
	{
		vars->bx = -(int)rastoinie->ax % 64 + 63 + (rastoinie->ax -
		(int)rastoinie->ax);
		vars->text.addr = vars->text.addr_s;
	}
}

void	count_rastoinie_res_7(t_rastoinie *rastoinie, t_vars *vars, double pow)
{
	vars->flag_wall = 0;
	if ((pow < 2 * M_PI && pow > 3 * M_PI / 2 && pow != M_PI_2)
	|| (pow > 0 && pow < M_PI_2))
	{
		vars->text.addr = vars->text.addr_e;
		vars->bx = (int)rastoinie->by % 64 + (rastoinie->by -
		(int)rastoinie->by);
	}
	else
	{
		vars->text.addr = vars->text.addr_w;
		vars->bx = -(int)rastoinie->by % 64 + 63 + (rastoinie->by -
		(int)rastoinie->by);
	}
}
