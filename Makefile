# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 08:55:39 by atahiri           #+#    #+#              #
#    Updated: 2020/11/26 10:07:42 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = Cub3d
AR = ar
LIBS = -lm -framework OpenGL -framework AppKit libs/libmlx.a
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