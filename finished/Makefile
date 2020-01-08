# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spentti <spentti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 17:17:12 by spentti           #+#    #+#              #
#    Updated: 2020/01/03 19:07:56 by spentti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBNAME = libft.a                                                                              
FLAGS = -Wall -Wextra -Werror
FRAME = -framework OpenGL -framework AppKit
LIB = -L minilibx/ -lmlx
SRC = srcs/*.c


all: $(NAME)

$(NAME): $(LIBNAME)
	gcc libft/libft.a $(SRC) $(LIB) $(FRAME) -o $(NAME)

$(LIBNAME):
	make -C libft/

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all