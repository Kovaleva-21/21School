/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 02:04:50 by student           #+#    #+#             */
/*   Updated: 2020/05/27 02:25:59 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void *arr;

	arr = (void*)malloc(num * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, num * size);
	return (arr);
}
