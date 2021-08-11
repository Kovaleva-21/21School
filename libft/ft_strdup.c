/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 02:47:18 by student           #+#    #+#             */
/*   Updated: 2020/05/28 01:39:27 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*j;

	i = 0;
	j = (char *)malloc(sizeof(*j) * ft_strlen(src) + 1);
	if (j == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		j[i] = src[i];
		i++;
	}
	j[i] = '\0';
	return (j);
}
