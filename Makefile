# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 08:55:39 by atahiri           #+#    #+#              #
#    Updated: 2020/11/01 15:11:28 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.a
AR = ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c gnl/*.c

all:$(NAME)

$(NAME):
	$(CC) -o Cub3d  -framework OpenGL -framework AppKit opengl/libmlx.a $(SRC) -g
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all