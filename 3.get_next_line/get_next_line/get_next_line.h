/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 00:10:27 by student           #+#    #+#             */
/*   Updated: 2020/08/04 00:51:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 34
# endif

char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *src);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *s, const char *p, size_t size);
char				*ft_strjoin(char const *s1, char const *s2);
int					get_next_line(int fd, char **line);

#endif
