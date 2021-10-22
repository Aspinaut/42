#!/bin/bash

SRCS =	srcs/main.c	\


LIBFT = libft/libft.a

NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	cd ./libft/ && make clean && cd ..

fclean:
	cd ./libft/ && make fclean && cd ..
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
