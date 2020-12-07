# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 08:55:39 by atahiri           #+#    #+#              #
#    Updated: 2020/12/07 14:36:24 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3D
AR = ar
LIBS = -l mlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Werror -Wextra
SRC = *.c gnl/*.c read_file/*.c utils/*.c

all:$(NAME)

$(NAME):
	@ $(CC) $(FLAGS) $(SRC) -o $(NAME) $(LIBS)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all
build:re
	./cub3D map.cub
norm:
	norminette *.c gnl/*.c read_file/*.c utils/*.c