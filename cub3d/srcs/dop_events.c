/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:50:42 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/26 18:25:29 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		events2(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
	{
		events10(events, vars);
		if (vars->mas[events->j][events->i] == '1' || vars->mas[events->jj]
		[events->ii] == '1' || vars->mas[events->jjj][events->iii] == '1')
			events->flag_wall = 1;
		events->count_wall++;
	}
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x -= 10 * cos((vars->alfa + M_PI_2));
		vars->y -= 10 * sin((vars->alfa + M_PI_2));
	}
	events->count_wall = 0;
}

void		events3(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
	{
		events8(events, vars);
		if (vars->mas[events->j][events->i] == '1' || vars->mas[events->jj]
		[events->ii] == '1' || vars->mas[events->jjj][events->iii] == '1')
			events->flag_wall = 1;
		events->count_wall++;
	}
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x -= 10 * cos(vars->alfa);
		vars->y -= 10 * sin(vars->alfa);
	}
	events->count_wall = 0;
}

void		events4(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
	{
		events9(events, vars);
		if (vars->mas[events->j][events->i] == '1' || vars->mas[events->jj]
		[events->ii] == '1' || vars->mas[events->jjj][events->iii] == '1')
			events->flag_wall = 1;
		events->count_wall++;
	}
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x += 10 * cos((vars->alfa + M_PI_2));
		vars->y += 10 * sin((vars->alfa + M_PI_2));
	}
	events->count_wall = 0;
}

void		events5(t_events *events, t_vars *vars)
{
	while (events->count_wall < 30)
	{
		events7(events, vars);
		if (vars->mas[events->j][events->i] == '1' || vars->mas[events->jj]
		[events->ii] == '1' || vars->mas[events->jjj][events->iii] == '1')
			events->flag_wall = 1;
		events->count_wall++;
	}
	if (events->flag_wall == 1)
	{
		vars->x += 0;
		vars->y += 0;
	}
	else
	{
		vars->x += 10 * cos(vars->alfa);
		vars->y += 10 * sin(vars->alfa);
	}
	events->count_wall = 0;
}

void		events6(t_events2 *events2, t_vars *vars)
{
	while (events2->count2 < vars->count_sprite - 1)
	{
		events2->len_sprite1 = sqrt((powf((vars->mas_sprite[events2->count] -
		vars->x), 2) + powf((vars->mas_sprite[events2->count2] - vars->y), 2)));
		events2->len_sprite2 = sqrt((powf((vars->mas_sprite[events2->count + 2]
		- vars->x), 2) + powf((vars->mas_sprite[events2->count2 + 2]
		- vars->y), 2)));
		events2->count += 2;
		events2->count2 += 2;
		if (events2->len_sprite1 < events2->len_sprite2)
		{
			events2->spr_x = vars->mas_sprite[events2->count - 2];
			events2->spr_y = vars->mas_sprite[events2->count2 - 2];
			vars->mas_sprite[events2->count - 2] =
			vars->mas_sprite[events2->count];
			vars->mas_sprite[events2->count2 - 2] =
			vars->mas_sprite[events2->count2];
			vars->mas_sprite[events2->count] = events2->spr_x;
			vars->mas_sprite[events2->count2] = events2->spr_y;
			break ;
		}
	}
	events2->count3++;
}
