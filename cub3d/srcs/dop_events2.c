/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:19:07 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/26 18:27:03 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		events7(t_events *events, t_vars *vars)
{
	events->i = (vars->x + events->count_wall *
	cos(vars->alfa)) / 64;
	events->j = (vars->y + events->count_wall *
	sin(vars->alfa)) / 64;
	events->ii = (vars->x + events->count_wall *
	cos(vars->alfa + M_PI / 6)) / 64;
	events->jj = (vars->y + events->count_wall *
	sin(vars->alfa + M_PI / 6)) / 64;
	events->iii = (vars->x + events->count_wall *
	cos(vars->alfa - M_PI / 6)) / 64;
	events->jjj = (vars->y + events->count_wall *
	sin(vars->alfa - M_PI / 6)) / 64;
}

void		events8(t_events *events, t_vars *vars)
{
	events->i = (vars->x - events->count_wall *
	cos(vars->alfa)) / 64;
	events->j = (vars->y - events->count_wall *
	sin(vars->alfa)) / 64;
	events->ii = (vars->x - events->count_wall *
	cos((vars->alfa + M_PI / 6))) / 64;
	events->jj = (vars->y - events->count_wall *
	sin((vars->alfa + M_PI / 6))) / 64;
	events->iii = (vars->x - events->count_wall *
	cos((vars->alfa - M_PI / 6))) / 64;
	events->jjj = (vars->y - events->count_wall *
	sin((vars->alfa - M_PI / 6))) / 64;
}

void		events9(t_events *events, t_vars *vars)
{
	events->i = (vars->x + events->count_wall *
	cos((vars->alfa + M_PI_2))) / 64;
	events->j = (vars->y + events->count_wall *
	sin((vars->alfa + M_PI_2))) / 64;
	events->ii = (vars->x + events->count_wall *
	cos((vars->alfa + M_PI_2 + M_PI / 6))) / 64;
	events->jj = (vars->y + events->count_wall *
	sin((vars->alfa + M_PI_2 + M_PI / 6))) / 64;
	events->iii = (vars->x + events->count_wall *
	cos((vars->alfa + M_PI_2 - M_PI / 6))) / 64;
	events->jjj = (vars->y + events->count_wall *
	sin((vars->alfa + M_PI_2 - M_PI / 6))) / 64;
}

void		events10(t_events *events, t_vars *vars)
{
	events->i = (vars->x - events->count_wall *
	cos((vars->alfa + M_PI_2))) / 64;
	events->j = (vars->y - events->count_wall *
	sin((vars->alfa + M_PI_2))) / 64;
	events->ii = (vars->x - events->count_wall *
	cos((vars->alfa + M_PI / 6 + M_PI_2))) / 64;
	events->jj = (vars->y - events->count_wall *
	sin((vars->alfa + M_PI / 6 + M_PI_2))) / 64;
	events->iii = (vars->x - events->count_wall *
	cos((vars->alfa - M_PI / 6 + M_PI_2))) / 64;
	events->jjj = (vars->y - events->count_wall *
	sin((vars->alfa - M_PI / 6 + M_PI_2))) / 64;
}
