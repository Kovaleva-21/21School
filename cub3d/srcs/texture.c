/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:20:55 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/19 19:50:22 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		error(char *str)
{
	ft_putstr_fd("Error\ntexture error ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void			pars_texture(t_vars *vars, char *str, char **adr, char *str2)
{
	int			count_mas;
	int			count_str;
	char		*reletiv_path;

	count_str = 0;
	count_mas = 0;
	reletiv_path = NULL;
	reletiv_path = ft_strtrim(str2, " ");
	vars->text.img = mlx_xpm_file_to_image(vars->mlx, reletiv_path,
	&vars->text.widht, &vars->text.heith);
	if (vars->text.img == NULL)
		error(str);
	if (vars->text.widht != 64 || vars->text.heith != 64)
	{
		ft_putstr_fd("Error\nplease select textures 64 * 64 px - ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}
	close(count_str);
	*adr = mlx_get_data_addr(vars->text.img, &vars->text.bits_per_pixel,
	&vars->text.line_length, &vars->text.endian);
	free(reletiv_path);
}
