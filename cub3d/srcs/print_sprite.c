/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:02:34 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/28 23:52:32 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	print_sprite_init(t_pr_sp *pr_sp, t_vars *vars,
double spr_y, double spr_x)
{
	pr_sp->i = 0;
	pr_sp->j = 0;
	pr_sp->sprite_dir = atan2(spr_y - vars->y, spr_x - vars->x);
	pr_sp->sprite_dist = sqrt((powf((spr_x - vars->x), 2) +
	powf((spr_y - vars->y), 2)));
	pr_sp->sprite_screen_size = vars->size_y * 64 / pr_sp->sprite_dist;
}

void		print_sprite2(t_pr_sp *pr_sp, t_vars *vars)
{
	pr_sp->v_offset = vars->size_y / 2 - pr_sp->sprite_screen_size / 2;
	while (pr_sp->sprite_dir - vars->alfa > M_PI)
		pr_sp->sprite_dir -= 2 * M_PI;
	while (pr_sp->sprite_dir - vars->alfa < -M_PI)
		pr_sp->sprite_dir += 2 * M_PI;
	pr_sp->h_offset = (pr_sp->sprite_dir - vars->alfa) * (vars->size_x)
	/ (M_PI / 3)
	+ (vars->size_x) / 2 - pr_sp->sprite_screen_size / 2;
	pr_sp->count = fabs((pr_sp->h_offset - vars->mas_ray[0]));
	pr_sp->step = M_PI / (vars->size_x * 3.0);
	if (pr_sp->sprite_screen_size > 4000)
		pr_sp->sprite_screen_size = 0;
}

void		print_sprite3(t_pr_sp *pr_sp, t_vars *vars)
{
	pr_sp->color = sp_get_color(vars, pr_sp->i * 64
	/ pr_sp->sprite_screen_size,
	pr_sp->j * 64 / pr_sp->sprite_screen_size);
	if (pr_sp->color != 0X00000)
		my_mlx_pixel_put(vars, pr_sp->h_offset + pr_sp->i,
		pr_sp->v_offset + pr_sp->j, pr_sp->color);
	pr_sp->j++;
}

void		print_sprite4(t_pr_sp *pr_sp, t_vars *vars)
{
	while (pr_sp->j < pr_sp->sprite_screen_size)
	{
		if (pr_sp->v_offset + (int)(pr_sp->j) < 0 || pr_sp->v_offset +
		pr_sp->j >= (int)vars->size_y)
		{
			pr_sp->j++;
			continue;
		}
		print_sprite3(pr_sp, vars);
	}
	pr_sp->step += M_PI / (vars->size_x * 3.0);
	pr_sp->j = 0;
	pr_sp->i++;
	pr_sp->count++;
}

void		print_sprite(double spr_x, double spr_y, t_vars *vars)
{
	t_pr_sp	pr_sp;

	print_sprite_init(&pr_sp, vars, spr_y, spr_x);
	print_sprite2(&pr_sp, vars);
	while (pr_sp.i < pr_sp.sprite_screen_size)
	{
		if (pr_sp.h_offset + (int)(pr_sp.i) < 0 || pr_sp.h_offset +
		pr_sp.i >= (int)vars->size_x)
		{
			pr_sp.i++;
			continue;
		}
		if (vars->mas_ray[pr_sp.h_offset + pr_sp.i] < pr_sp.sprite_dist)
		{
			pr_sp.i++;
			continue;
		}
		print_sprite4(&pr_sp, vars);
	}
}
