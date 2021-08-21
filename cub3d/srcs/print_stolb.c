/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stolb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:43:07 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/26 22:05:19 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_stolb(t_stolb *stolb, t_vars *vars, double angle_ray)
{
	stolb->len = vars->len_ray;
	stolb->len = stolb->len * cos(vars->alfa - angle_ray);
	stolb->len_stolb = vars->size_y * 64 / stolb->len;
	stolb->start = vars->size_y / 2 - stolb->len_stolb / 2;
	stolb->yyy = stolb->start;
	stolb->end = vars->size_y / 2 + stolb->len_stolb / 2;
	stolb->coef = 64.0 / (stolb->start - stolb->end);
	stolb->count = 0;
	stolb->color = 0;
	stolb->count_y_pixel = 0;
	stolb->count_x_pixel = vars->bx;
}

void		print_stolb(t_vars *vars, double angle_ray)
{
	t_stolb		stolb;

	init_stolb(&stolb, vars, angle_ray);
	if (stolb.start < 0)
		stolb.start = 0;
	while (stolb.count < stolb.start)
	{
		my_mlx_pixel_put(vars, vars->count_plan, stolb.count, vars->color_f);
		stolb.count++;
	}
	while (stolb.start < stolb.end && stolb.start < vars->size_y
	&& stolb.start >= 0)
	{
		stolb.count_y_pixel = (int)((stolb.yyy - stolb.start) * stolb.coef);
		stolb.color = get_color(vars, stolb.count_x_pixel, stolb.count_y_pixel);
		my_mlx_pixel_put(vars, vars->count_plan, stolb.start, stolb.color);
		stolb.start++;
	}
	while (stolb.end < vars->size_y)
	{
		my_mlx_pixel_put(vars, vars->count_plan, stolb.end, vars->color_c);
		stolb.end++;
	}
	vars->count_plan++;
}
