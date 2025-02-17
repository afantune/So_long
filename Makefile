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
SRC = src/game.c src/utilities.c src/maprules.c src/map_loader.c src/errors.c src/frees.c src/position.c

NAME = so_long
LIB = so_long.a
OBJ = $(SRC:.c=.o)
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    MACOS_FLAGS = -framework OpenGL -framework AppKit
else
    MACOS_FLAGS =
endif

all: $(LIB)
	cd minilibx-linux && make 
	cd get_next_line && make
	cd printf && make
	$(CC) $(CFLAGS) ./src/maps.c $(LIB) ./get_next_line/gnl.a ./printf/libftprintf.a -Lmlx -lmlx $(MACOS_FLAGS) -o $(NAME)

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



