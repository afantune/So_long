# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afantune <afantune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 13:42:55 by afantune          #+#    #+#              #
#    Updated: 2025/04/08 14:18:01 by afantune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/checks.c src/displays.c src/errors.c src/frees.c src/game.c src/map_loader.c src/maprules.c \
src/player.c src/position.c src/utilities.c src/food.c src/exit.c src/wall.c src/listmanager.c src/loading.c

NAME = so_long
LIB = so_long.a
OBJ = $(SRC:.c=.o)

all: $(LIB)
	cd minilibx-linux && make 
	cd get_next_line && make
	cd printf && make
	$(CC) $(CFLAGS) ./src/maps.c $(LIB) ./get_next_line/gnl.a ./printf/libftprintf.a ./minilibx-linux/libmlx.a -Iminilibx-linux -lXext -lX11 -lm -lz -o  $(NAME)

$(LIB): $(OBJ)
	@ar -rcs $(LIB) $(OBJ)

clean:
		rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME) $(LIB)
	make -C minilibx-linux clean
	make -C get_next_line fclean
	make -C printf fclean



