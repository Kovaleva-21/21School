/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuckt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:27:59 by ccorliss          #+#    #+#             */
/*   Updated: 2020/11/26 18:36:34 by ccorliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include "cub.h"

void		save_map(char *line, char **map)
{
	static int i;

	if (line == NULL)
		map[i] = NULL;
	else
	{
		map[i] = ft_strdup(line);
		i++;
	}
}

int			main(int argc, char **argv)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	line = ft_strdup("");
	map = malloc(sizeof(char) * 10);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		save_map(line, map);
		free(line);
	}
	save_map(line, map);
	free(line);
	save_map(NULL, map);
	while (map[i] != NULL)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (0);
}
