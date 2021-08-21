/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:50:02 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 22:34:39 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		init_events(t_events *events)
{
	events->i = 0;
	events->j = 0;
	events->ii = 0;
	events->jj = 0;
	events->iii = 0;
	events->jjj = 0;
	events->flag_wall = 0;
	events->count_wall = 1;
}

void		init_events2(t_events2 *events2)
{
	events2->count = 0;
	events2->count2 = 1;
	events2->count3 = 0;
	events2->len_sprite1 = 0;
	events2->len_sprite2 = 0;
	events2->spr_x = 0;
	events2->spr_y = 0;
}
