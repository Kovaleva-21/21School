/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 01:32:30 by student           #+#    #+#             */
/*   Updated: 2020/05/31 19:44:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

size_t			ft_strlcat(char *s, const char *p, size_t size);
int				ft_strncmp(const char *arr1, const char *arr2, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isprint(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
void			ft_bzero(void *s, size_t n);
int				ft_atoi(const char *str);
char			*ft_strdup(const char *src);
size_t			ft_strlen(const char *str);
void			*ft_memcpy(void *s, const void *p, size_t n);
void			*ft_memccpy(void *s, const void *p, int c, size_t n);
void			*ft_memmove(void *s, const void *p, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlcpy(char *s, const char *p, size_t size);
size_t			ft_strlcat(char *s, const char *p, size_t size);
void			*ft_calloc(size_t num, size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strnstr(const char *s, const char *p, size_t n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_itoa(int n);
char			**ft_split(char	const *s, char c);
#endif
