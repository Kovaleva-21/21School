/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:24:43 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/27 17:24:46 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nam, size_t size)
{
	void	*ptr;

	ptr = (void*)malloc(size * nam);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, size * nam);
	return (ptr);
}
