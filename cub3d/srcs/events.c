/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:30:11 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 23:07:18 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	events_dop(t_vars *vars)
{
	t_events2 events2;

	print_player(vars);
	init_events2(&events2);
	while (events2.count3 < vars->count_sprite - 1)
		events6(&events2, vars);
	events2.count = 0;
	events2.count2 = 1;
	while (events2.count2 < vars->count_sprite)
	{
		print_sprite(vars->mas_sprite[events2.count],
		vars->mas_sprite[events2.count2], vars);
		events2.count += 2;
		events2.count2 += 2;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

static void	code(int keycode, t_vars *vars)
{
	if (keycode == 124)
	{
		vars->alfa += 0.0872665;
		if (vars->alfa >= 2 * M_PI)
			vars->alfa -= 2 * M_PI;
	}
	if (keycode == 123)
	{
		vars->alfa -= 0.0872665;
		if (vars->alfa <= 0)
			vars->alfa += 2 * M_PI;
	}
}

int			events(int keycode, t_vars *vars)
{
	t_events events;

	init_events(&events);
	if (keycode == 53)
		exit(0);
	if (keycode == 17)
		exit(0);
	if (keycode == 0)
		events2(&events, vars);
	if (keycode == 1)
		events3(&events, vars);
	if (keycode == 2)
		events4(&events, vars);
	if (keycode == 13)
		events5(&events, vars);
	code(keycode, vars);
	mlx_destroy_image(vars->mlx, vars->img.img);
	vars->img.img = mlx_new_image(vars->mlx, vars->size_x, vars->size_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
	&vars->img.line_length, &vars->img.endian);
	vars->count_plan = 0;
	events_dop(vars);
	return (0);
}
