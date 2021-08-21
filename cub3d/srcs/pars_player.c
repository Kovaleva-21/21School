/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:51:37 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/22 20:16:13 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->i = 0;
	player->j = 0;
}

static void		pars_player2(t_player *player, t_vars *vars)
{
	if (vars->mas[player->j][player->i] == 'N')
	{
		vars->x = player->x + 32;
		vars->y = player->y + 32;
		vars->alfa = 3 * M_PI / 2;
	}
	if (vars->mas[player->j][player->i] == 'S')
	{
		vars->x = player->x + 32;
		vars->y = player->y + 32;
		vars->alfa = M_PI_2;
	}
	if (vars->mas[player->j][player->i] == 'E')
	{
		vars->x = player->x + 32;
		vars->y = player->y + 32;
		vars->alfa = 0;
	}
	if (vars->mas[player->j][player->i] == 'W')
	{
		vars->x = player->x + 32;
		vars->y = player->y + 32;
		vars->alfa = M_PI;
	}
}

static void		pars_player2_2(t_player *player, t_vars *vars)
{
	while (vars->mas[player->j][player->i] != '\0')
	{
		pars_player2(player, vars);
		if (vars->mas[player->j][player->i] == '2')
			vars->count_sprite++;
		player->x += 64;
		player->i++;
	}
}

static void		pars_player3(t_player *player, t_vars *vars)
{
	while (vars->mas[player->j][player->i] != '\0')
	{
		if (vars->mas[player->j][player->i] == '2')
		{
			vars->mas_sprite[vars->count_sprite] = player->x + 32;
			vars->count_sprite++;
			vars->mas_sprite[vars->count_sprite] = player->y + 32;
			vars->count_sprite++;
		}
		player->x += 64;
		player->i++;
	}
	player->x = 0;
	player->i = 0;
	player->j++;
	player->y += 64;
}

void			pars_player(t_vars *vars)
{
	t_player player;

	init_player(&player);
	vars->count_sprite = 0;
	while (vars->mas[player.j] != NULL)
	{
		pars_player2_2(&player, vars);
		player.x = 0;
		player.i = 0;
		player.j++;
		player.y += 64;
	}
	player.y = 0;
	player.j = 0;
	if (vars->mas_sprite != NULL)
		free(vars->mas_sprite);
	vars->mas_sprite = malloc(sizeof(int) * vars->count_sprite * 2);
	if (!vars->mas_sprite)
	{
		ft_putstr_fd("Error\nmallok par_palyer\n", 2);
		exit(0);
	}
	vars->count_sprite = 0;
	while (vars->mas[player.j] != NULL)
		pars_player3(&player, vars);
}
