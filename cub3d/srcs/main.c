/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 20:20:27 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 21:12:58 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	print(t_vars *vars, char **argv)
{
	pars_cub(argv, vars);
	valid_mup_cub(vars);
	init_window(vars);
	pars_player(vars);
	print_player(vars);
	sort_sprite(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_hook(vars->win, 2, 0L, events, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_loop(vars->mlx);
}

static void	scrin(t_vars *vars, char **argv)
{
	pars_cub(argv, vars);
	valid_mup_cub(vars);
	init_window(vars);
	pars_player(vars);
	print_player(vars);
	sort_sprite(vars);
	skrinshot(vars);
}

static void	ar(t_vars *vars, char **argv)
{
	if (ft_strncmp(argv[2], "--save", 7) == 0)
		scrin(vars, argv);
	else
	{
		ft_putstr_fd("Error\nWrong two argument\n", 2);
		exit(0);
	}
}

int			main(int argc, char **argv)
{
	t_vars	vars;
	int		i;

	i = ft_strlen(argv[1]);
	vars.mas_sprite = NULL;
	vars.count_plan = 0;
	null_funk(&vars);
	vars.mlx = mlx_init();
	if (argc < 2 || argc > 3)
	{
		ft_putstr_fd("Error\nWrong argument\n", 2);
		exit(0);
	}
	if (ft_strncmp(&argv[1][i - 4], ".cub", 5))
	{
		ft_putstr_fd("Error\nWrong format conf file\n", 2);
		exit(0);
	}
	if (argc == 3)
	{
		ar(&vars, argv);
	}
	print(&vars, argv);
	return (0);
}
