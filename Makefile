# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 08:55:39 by atahiri           #+#    #+#              #
#    Updated: 2020/11/22 12:21:39 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.a
AR = ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c gnl/*.c read_file/*.c utils/*.c

all:$(NAME)

$(NAME):
	$(CC) -o Cub3d  -framework OpenGL -framework AppKit -l mlx $(SRC) -g
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all