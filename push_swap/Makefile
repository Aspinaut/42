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
		srcs/stack_cpy.c	\
		srcs/push.c	\
		srcs/swap.c	\
		srcs/rotate.c	\
		srcs/reverse_rotate.c	\
		srcs/small_sort.c	\
		srcs/big_sort.c	\
		srcs/push_swap_utils.c	\

LIBFT = libft/libft.a

NAME = push_swap

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
