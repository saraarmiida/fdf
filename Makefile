# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 17:17:12 by spentti           #+#    #+#              #
#    Updated: 2019/11/27 13:40:12 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
FRAME = -framework OpenGL -framework AppKit
LIB = -L minilibx/ -lmlx
SRC = line_algorithm.c read_file.c

all:
	gcc libft/libft.a $(SRC) $(LIB) $(FRAME)

clean:

fclean: clean
	rm -f a.out

re: fclean all