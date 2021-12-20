#!/bin/bash

SRCS =	srcs/child.c	\
		srcs/main.c	\
		srcs/pipex.c	\
		srcs/utils.c	\

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

NAME = pipex

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME)

all: $(NAME)

$(LIBFT): 
	$(MAKE) -C ./libft

clean:
	$(RM) $(OBJS) && cd ./libft/ && make clean && cd ..

fclean: clean
	$(RM) $(NAME) && $(RM) ./libft/libft.a

re: fclean all

.PHONY: clean fclean re all
