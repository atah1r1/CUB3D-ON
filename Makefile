# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 08:55:39 by atahiri           #+#    #+#              #
#    Updated: 2020/10/22 13:31:38 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.a
AR = ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c gnl/*.c

all:$(NAME)

$(NAME):
	$(CC) -o Cub3d  -framework OpenGL -framework AppKit -l mlx $(SRC) -g
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all