/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 23:16:59 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 23:15:59 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_sprite(t_sprite *sprite)
{
	sprite->count = 0;
	sprite->count2 = 1;
	sprite->count3 = 0;
	sprite->len_sprite1 = 0;
	sprite->len_sprite2 = 0;
	sprite->spr_x = 0;
	sprite->spr_y = 0;
}

static void		sort_sprite_2(t_sprite *sprite, t_vars *vars)
{
	sprite->spr_x = vars->mas_sprite[sprite->count - 2];
	sprite->spr_y = vars->mas_sprite[sprite->count2 - 2];
	vars->mas_sprite[sprite->count - 2] = vars->mas_sprite[sprite->count];
	vars->mas_sprite[sprite->count2 - 2] = vars->mas_sprite[sprite->count2];
	vars->mas_sprite[sprite->count] = sprite->spr_x;
	vars->mas_sprite[sprite->count2] = sprite->spr_y;
}

static void		sort_sprite_3(t_sprite *sprite, t_vars *vars)
{
	sprite->len_sprite1 = sqrt((powf((vars->mas_sprite[sprite->count]
	- vars->x), 2) + powf((vars->mas_sprite[sprite->count2] - vars->y), 2)));
	sprite->len_sprite2 = sqrt((powf((vars->mas_sprite[sprite->count + 2] -
	vars->x), 2) + powf((vars->mas_sprite[sprite->count2 + 2] - vars->y), 2)));
	sprite->count += 2;
	sprite->count2 += 2;
}

void			sort_sprite(t_vars *vars)
{
	t_sprite	sprite;

	sprite.count = 0;
	sprite.count2 = 1;
	init_sprite(&sprite);
	while (sprite.count3 < vars->count_sprite - 1)
	{
		while (sprite.count2 < vars->count_sprite - 1)
		{
			sort_sprite_3(&sprite, vars);
			if (sprite.len_sprite1 < sprite.len_sprite2)
			{
				sort_sprite_2(&sprite, vars);
				break ;
			}
		}
		sprite.count3++;
	}
	while (sprite.count2 < vars->count_sprite)
	{
		print_sprite(vars->mas_sprite[sprite.count],
		vars->mas_sprite[sprite.count2], vars);
		sprite.count += 2;
		sprite.count2 += 2;
	}
}
