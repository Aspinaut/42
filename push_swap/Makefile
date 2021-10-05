#!/bin/bash

SRCS =	srcs/main.c	\
		srcs/args_checker.c	\
		srcs/stack_addback.c	\
		srcs/stack_addfront.c	\
		srcs/stack_addnew.c	\
		srcs/stack_clear.c	\
		srcs/stack_delone.c	\
		srcs/stack_size.c	\
		srcs/stack_last.c	\
		srcs/push.c	\
		srcs/swap.c	\
		srcs/rotate.c	\
		srcs/reverse_rotate.c	\
		srcs/small_sort.c	\
		srcs/push_swap_utils.c	\

LIBFT = libft/libft.a

NAME = push_swap

RM = rm -f

CC = gcc

# CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra

$(LIBFT):
	cd ./libft/ && make && cd ..

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -g -o $(NAME)

all: $(LIBFT) $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	cd ./libft/ && make fclean && cd ..

re: fclean all

.PHONY: clean fclean re all
