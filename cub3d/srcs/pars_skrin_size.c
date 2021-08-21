/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_skrin_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:27:13 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/23 21:42:04 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		init_skrin(t_skrin *skrin)
{
	skrin->ptr = NULL;
	skrin->flag = 0;
	skrin->count_str = 0;
	skrin->count_mas = 0;
}

static void		pars_skrin_size2(t_skrin *skrin, char *mas)
{
	if (ft_isdigit(mas[skrin->count_str]) && skrin->flag == 0)
	{
		skrin->x = ft_atoi(&mas[skrin->count_str]);
		skrin->count_str += ft_strlen((skrin->ptr = ft_itoa(skrin->x)));
		free(skrin->ptr);
		skrin->flag = 1;
	}
	if (ft_isdigit(mas[skrin->count_str]) && skrin->flag == 1)
	{
		skrin->y = ft_atoi(&mas[skrin->count_str]);
		skrin->count_str += ft_strlen((skrin->ptr = ft_itoa(skrin->y)));
		free(skrin->ptr);
		skrin->flag = 2;
	}
	if (mas[skrin->count_str] != ' ' && mas[skrin->count_str] != '\0')
	{
		ft_putstr_fd("Error\nerror in resolution\n", 2);
		exit(0);
	}
}

static void		pars_skrin_size2_2(t_skrin *skrin, char *mas)
{
	while (mas[skrin->count_str] != '\0')
	{
		pars_skrin_size2(skrin, mas);
		if (mas[skrin->count_str] == ' ')
		{
			skrin->count_str++;
			continue;
		}
		if (mas[skrin->count_str] == ' ')
		{
			skrin->count_str++;
			continue;
		}
	}
}

int				pars_skrin_size(t_vars *vars, char *mas)
{
	t_skrin skrin;

	init_skrin(&skrin);
	skrin.count_str++;
	pars_skrin_size2_2(&skrin, mas);
	skrin.count_mas++;
	skrin.count_str = 0;
	if (skrin.x > 2147483647 || skrin.y > 2147483647)
	{
		ft_putstr_fd("Error\nvery big resolution at least 2147483647 pix\n", 2);
		exit(0);
	}
	if (skrin.x <= 0 || skrin.y <= 0)
	{
		ft_putstr_fd("Error\nvery small resolution at least 10 pixels\n", 2);
		exit(0);
	}
	vars->size_x = (int)skrin.x;
	vars->size_y = (int)skrin.y;
	mlx_get_screen_size(vars->mlx, &skrin.count_mas, &skrin.count_str);
	if ((int)vars->size_x > skrin.count_mas)
		vars->size_x = skrin.count_mas - 1;
	if ((int)vars->size_y > skrin.count_str)
		vars->size_y = skrin.count_str;
	return (0);
}
