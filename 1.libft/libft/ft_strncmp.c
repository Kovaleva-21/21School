/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:56:49 by student           #+#    #+#             */
/*   Updated: 2020/05/27 15:31:18 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *arr1, const char *arr2, size_t n)
{
	while ((*arr1 || *arr2) && n != 0)
	{
		if (*arr1 != *arr2)
			return ((unsigned char)*arr1 - *arr2);
		arr1++;
		arr2++;
		n--;
	}
	return (0);
}
