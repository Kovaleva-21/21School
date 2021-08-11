# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/08 17:56:45 by student           #+#    #+#              #
#    Updated: 2020/06/23 00:04:25 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror
INCLUDES = ft_printf.h
SRC = ft_printf.c \
	printf_c.c printf_d.c \
	printf_p.c printf_proc.c \
	printf_s.c printf_u.c \
	printf_x.c put1.c put2.c check_flags.c \
	check_symbols.c ft_lib.c \
	get_num.c \

OBJECTS = $(SRC:.c=.o)



all : $(NAME)

$(NAME): $(OBJECTS)  $(INCLUDES)
	@ar rc $(NAME) $(OBJECTS)

%.o:%.c $(INCLUDES)
	@gcc $(FLAGS)  -c $< -o $@

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re