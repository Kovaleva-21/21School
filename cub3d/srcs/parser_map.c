/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:19:08 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/27 17:45:48 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		print_poz(t_vars *vars)
{
	int c;

	c = 0X8B0000;
	my_mlx_pixel_put(vars, vars->x * 0.15625, vars->y * 0.15625, c);
	my_mlx_pixel_put(vars, vars->x * 0.15625 + 1, vars->y * 0.15625, c);
	my_mlx_pixel_put(vars, vars->x * 0.15625, vars->y * 0.15625 + 1, c);
	my_mlx_pixel_put(vars, vars->x * 0.15625 - 1, vars->y * 0.15625, c);
	my_mlx_pixel_put(vars, vars->x * 0.15625, vars->y * 0.15625 - 1, c);
}

void		print_player(t_vars *vars)
{
	double	start;
	double	end;
	double	step;
	int		len;

	start = vars->alfa - M_PI / 6;
	end = vars->alfa + M_PI / 6;
	step = M_PI / (vars->size_x * 3.0);
	len = 0;
	while (start < (end - step))
	{
		vars->len_ray = count_rastoinie(vars->mas,
		start, vars);
		print_stolb(vars, start);
		start += step;
		vars->mas_ray[len] = vars->len_ray;
		len++;
	}
}

char		**save_map(int size, t_list **tmp)
{
	int		i;
	char	**map;
	t_list	*list;

	i = 0;
	map = ft_calloc(size + 2, sizeof(char *));
	list = *tmp;
	while (list)
	{
		map[i] = ft_strdup(list->content);
		list = list->next;
		i++;
	}
	map[i] = ft_strdup("");
	map[i + 1] = NULL;
	ft_lstclear(tmp, free);
	return (map);
}

int			pars_cub(char **argv, t_vars *vars)
{
	int		fd;
	char	*line;
	t_list	*tmp;

	fd = open(argv[1], O_RDONLY);
	line = NULL;
	tmp = NULL;
	if (fd == -1)
	{
		ft_putstr_fd("Error\ndid not find the file with the map\n", 2);
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&tmp, ft_lstnew(line));
	}
	ft_lstadd_back(&tmp, ft_lstnew(line));
	vars->mas = save_map(ft_lstsize(tmp), &tmp);
	return (0);
}

void		null_funk(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->x = 0;
	vars->y = 0;
	vars->bx = 0;
	vars->len_sprite = 0;
	vars->mas = NULL;
	vars->alfa = 0;
	vars->start = 0;
	vars->flag_wall = 0;
	vars->count_plan = 0;
	vars->len_ray = 0;
	vars->count_sprite = 0;
	vars->mas_sprite = NULL;
	vars->size_x = 0;
	vars->size_y = 0;
	vars->color_f = 0;
	vars->color_c = 0;
}
