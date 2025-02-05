# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afantune <afantune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:42:55 by afantune          #+#    #+#              #
#    Updated: 2025/02/05 14:11:08 by afantune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC =

NAME = so_long
LIB = so_long.a
OBJ = $(SRC:.c=.o)

all: $(LIB)
	cd mlx && make
	cd get_next_line && make
	cd printf && make
	@$(CC) $(CFLAGS) ./src/maps.c $(LIB) ./get_next_line/gnl.a ./printf/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB): $(OBJ)
	@ar -rcs $(LIB) $(OBJ)

clean:
		rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME) $(LIB)
	make -C mlx clean
	make -C get_next_line fclean
	make -C printf fclean
