#!/bin/bash

SRCS =	srcs/main.c	\
		srcs/args_checker.c	\

LIBFT = libft/libft.a

NAME = push_swap

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(LIBFT):
	cd ./libft/ && make && cd ..

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all: $(LIBFT) $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	cd ./libft/ && make fclean && cd ..

re: fclean all

.PHONY: clean fclean re all
