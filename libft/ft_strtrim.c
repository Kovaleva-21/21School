/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 00:59:20 by student           #+#    #+#             */
/*   Updated: 2020/05/30 01:09:07 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	trim = (char *)s1;
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && (ft_strrchr(set, s1[i])) != 0)
		i++;
	while (s1[i] && (ft_strrchr(set, s1[j - 1]) != 0))
		j--;
	if (!(trim = ft_substr(trim, i, j - i)))
		return (NULL);
	return (trim);
}
