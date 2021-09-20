#!/bin/bash

SRCS =	srcs/child.c	\
		srcs/main.c	\
		srcs/pipex.c	\
		srcs/utils.c	\

LIBFT = libft/libft.a

NAME = pipex

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
