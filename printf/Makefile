# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afantune <afantune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 10:28:26 by afantune          #+#    #+#              #
#    Updated: 2025/02/05 13:58:41 by afantune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_printf.c ft_format.c ft_putnbr.c ft_putnbr_base.c ft_putstr.c ft_putchar.c \
	ft_char_conversion.c ft_string_conversion.c ft_pointer_conversion.c \
	ft_int_conversion.c ft_unsigned_conversion.c ft_lowerhex_conversion.c \
	ft_upperhex_conversion.c ft_percent_conversion.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = @cc
CFLAGS = -Wall -Wextra -Werror
AR = @ar
RM = @rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
