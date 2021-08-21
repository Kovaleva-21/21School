/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:19:55 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 22:55:05 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		my_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char *dst;

	dst = data->img.addr + (y * data->img.line_length + x *
			(data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			get_color(t_vars *data, int x, int y)
{
	char *dst;

	dst = data->text.addr + (y * data->text.line_length + x *
			(data->text.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

int			sp_get_color(t_vars *data, int x, int y)
{
	char *dst;

	dst = data->text.addr_spr + (y * data->text.line_length + x *
			(data->text.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void		init_window(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, vars->size_x, vars->size_y, "Cub3D");
	vars->img.img = mlx_new_image(vars->mlx, vars->size_x, vars->size_y);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->
			img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}

int			ft_close(void)
{
	exit(0);
}
