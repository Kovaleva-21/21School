/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flor_ceilling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:46:29 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/25 22:34:10 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		init_flor(t_flor *flor)
{
	flor->ptr = NULL;
	flor->flag = 0;
	flor->count_str = 0;
	flor->count_mas = 0;
}

void		init_color(t_color *color)
{
	color->ptr = NULL;
	color->flag = 0;
	color->count_str = 0;
	color->count_mas = 0;
}
