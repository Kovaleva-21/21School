# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorliss <ccorliss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/08 17:56:45 by ccorliss          #+#    #+#              #
#    Updated: 2020/11/27 18:08:35 by ccorliss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MLX_LIB = libmlx.dylib

MLX = minilibx_mms_20200219

OBJ_FILES = srcs/parser_map.o srcs/skrinshoot.o srcs/texture.o srcs/print_sprite.o \
srcs/print_stolb.o srcs/rastoinie.o srcs/sort_sprite.o srcs/events.o srcs/init_events.o \
srcs/dop_events.o srcs/pars_player.o srcs/pars_skrin_size.o srcs/pars_flor_color.o \
srcs/init_flor_ceilling.o srcs/valid_mup_cub.o srcs/valid_mup.o srcs/valid_pars.o \
srcs/pars_ceilling_color.o srcs/main.o srcs/ft.o srcs/dop_events2.o srcs/rastoinie_dop.o\
libft/ft_strlen.o \
libft/ft_strchr.o libft/ft_strjoin.o libft/ft_putstr_fd.o libft/ft_strncmp.o \
libft/ft_atoi.o libft/ft_isdigit.o libft/ft_itoa.o libft/ft_lstadd_back.o \
libft/ft_lstnew.o libft/ft_lstsize.o libft/ft_strtrim.o libft/ft_calloc.o \
libft/ft_strdup.o libft/ft_lstclear.o libft/ft_memcpy.o libft/ft_memset.o \
libft/ft_putchar_fd.o get_next_line/get_next_line.o  

CFLAGS = -Wall -Wextra -Werror -g

FLAG_LINK = libmlx.dylib -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ_FILES) srcs/cub.h
	make -C $(MLX)
	mv $(MLX)/$(MLX_LIB) ./
	gcc $(FLAG_LINK) $(OBJ_FILES) -o $(NAME)

%.o: %.c 
	gcc -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re
