/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_mup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:23:17 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/24 23:12:42 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		valid_mup2(t_vars *vars, int count_mas, int count_str)
{
	if (vars->mas[count_mas][count_str] == '0' ||
	vars->mas[count_mas][count_str] == '2'
	|| ft_strchr("NSWE", vars->mas[count_mas][count_str]))
	{
		if (count_str == 0)
		{
			ft_putstr_fd("Error\nmap error\n", 2);
			exit(0);
		}
		if (vars->mas[count_mas][count_str + 1] == ' ' || vars->mas[count_mas]
		[count_str - 1] == ' ' || vars->mas[count_mas + 1][count_str] == ' '
		|| vars->mas[count_mas - 1][count_str] == ' ' || vars->mas[count_mas]
		[count_str + 1] == '\0' || vars->mas[count_mas][count_str - 1] == '\0'
		|| vars->mas[count_mas + 1][count_str] == '\0' ||
		vars->mas[count_mas - 1]
		[count_str] == '\0' || (int)ft_strlen(vars->mas[count_mas - 1])
		< count_str ||
		(vars->mas[count_mas + 1] != NULL &&
		(int)ft_strlen(vars->mas[count_mas + 1]) < count_str))
		{
			ft_putstr_fd("Error\nmap error\n", 2);
			exit(0);
		}
	}
}

int				valid_mup(t_vars *vars, int count_mas, int count_str)
{
	while (vars->mas[count_mas] != NULL)
	{
		while (vars->mas[count_mas][count_str] != '\0')
		{
			if (vars->mas[count_mas][count_str] == '1' ||
			vars->mas[count_mas][count_str] ==
			'0' || vars->mas[count_mas][count_str] == '2'
			|| ft_strchr("NSWE", vars->mas[count_mas]
			[count_str]) || vars->mas[count_mas][count_str] == ' ')
				valid_mup2(vars, count_mas, count_str);
			else
			{
				ft_putstr_fd("Error\nmap error\n", 2);
				exit(0);
			}
			count_str++;
		}
		count_str = 0;
		count_mas++;
	}
	return (0);
}
