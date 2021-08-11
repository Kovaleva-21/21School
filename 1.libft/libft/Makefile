# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/08 17:56:45 by student           #+#    #+#              #
#    Updated: 2020/05/31 19:50:12 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = ./
HEADER = libft.h
SRC = ./ft_atoi.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strlcpy.c\
	  ft_calloc.c\
	  ft_isalnum.c\
	  ft_isalpha.c\
	  ft_isascii.c\
	  ft_isdigit.c\
	  ft_isprint.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_strlcat.c\
	  ft_strncmp.c\
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strnstr.c \
	  ft_strmapi.c \
	  ft_itoa.c \
	  ft_split.c
OBJECTS = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o:%.c $(HEADER)
	@gcc $(FLAGS) -I$(INCLUDES) -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
