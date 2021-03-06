/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 22:51:24 by student           #+#    #+#             */
/*   Updated: 2020/05/31 11:38:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long		j;

	i = 1;
	j = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		j = j * 10 + (*str - '0');
		str++;
		if (j > 9223372036854775807)
		{
			if (i == -1)
				return (0);
			return (-1);
		}
	}
	return (j * i);
}
