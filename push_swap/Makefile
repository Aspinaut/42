#!/bin/bash

SRCS =	srcs/main.c	\
		srcs/args_checker.c	\
		srcs/stack_addback.c	\
		srcs/stack_addfront.c	\
		srcs/stack_addnew.c	\
		srcs/stack_clear.c	\
		srcs/stack_delone.c	\
		srcs/stack_size.c	\

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