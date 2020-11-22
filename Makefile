# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 08:55:39 by atahiri           #+#    #+#              #
#    Updated: 2020/11/22 17:15:32 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = cub3d.a
AR = ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c gnl/*.c read_file/*.c utils/*.c

all:$(NAME)

$(NAME):
	$(CC) -o Cub3d  -framework OpenGL -framework AppKit libs/libmlx.a $(SRC) -g
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all