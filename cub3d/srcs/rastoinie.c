/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rastoinie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 18:27:55 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/26 22:07:17 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_rastoinie(t_rastoinie *rastoinie, t_vars *vars)
{
	rastoinie->xa = 0;
	rastoinie->ya = 0;
	rastoinie->px = vars->x;
	rastoinie->py = vars->y;
	rastoinie->ay = 0;
	rastoinie->ax = 0;
	rastoinie->bx = 0;
	rastoinie->by = 0;
	rastoinie->len_gor = 0;
	rastoinie->len_ver = 0;
	rastoinie->i = 0;
	rastoinie->j = 0;
	rastoinie->i1 = 0;
	rastoinie->j1 = 0;
	rastoinie->end_mas_y = 0;
}

void			count_rastoinie_res(t_rastoinie *rastoinie, double pow)
{
	rastoinie->ay = (int)(rastoinie->py / 64) * 64 + 64;
	rastoinie->ya = 64;
	rastoinie->ax = rastoinie->px + (rastoinie->py - rastoinie->ay)
	/ tan((M_PI * 2 - pow));
	rastoinie->xa = 64 / tan(pow);
}

void			count_rastoinie_res_2(t_rastoinie *rastoinie, double pow)
{
	if (pow > 0 && pow < M_PI)
		count_rastoinie_res(rastoinie, pow);
	else if (pow == M_PI || pow == 0)
	{
		rastoinie->ay = rastoinie->py;
		rastoinie->ya = 64;
	}
	else
	{
		rastoinie->ay = (int)(rastoinie->py / 64) * 64 - 0.000000001;
		rastoinie->ya = -64;
		rastoinie->ax = rastoinie->px + (rastoinie->py - rastoinie->ay)
		/ tan((M_PI * 2 - pow));
		rastoinie->xa = 64 / tan(M_PI * 2 - pow);
	}
	rastoinie->i = rastoinie->ax / 64;
	rastoinie->j = rastoinie->ay / 64;
}

int				count_rastoinie(char **mas,
double pow, t_vars *vars)
{
	t_rastoinie	rastoinie;

	init_rastoinie(&rastoinie, vars);
	if (pow < 0)
		pow += 2 * M_PI;
	if (pow > 2 * M_PI)
		pow -= 2 * M_PI;
	while (mas[rastoinie.end_mas_y] != NULL)
		rastoinie.end_mas_y++;
	count_rastoinie_res_2(&rastoinie, pow);
	count_rastoinie_res_3(&rastoinie, mas);
	count_rastoinie_res_4(&rastoinie, pow);
	count_rastoinie_res_5(&rastoinie, mas);
	if (rastoinie.len_gor <= rastoinie.len_ver)
	{
		count_rastoinie_res_6(&rastoinie, vars, pow);
		return (rastoinie.len_gor);
	}
	else
	{
		count_rastoinie_res_7(&rastoinie, vars, pow);
		return (rastoinie.len_ver);
	}
}
