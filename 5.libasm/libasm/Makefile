# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/08 17:56:45 by student           #+#    #+#              #
#    Updated: 2020/12/06 13:29:58 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
FLAGS = -f macho64
INCLUDES = ./ 
HEADER = libasm.h
SRC = ./ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJECTS = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

%.o:%.s $(HEADER)
	@ nasm $(FLAGS) -I$(INCLUDES) $< 

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re