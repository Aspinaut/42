#!/bin/bash

SRCS =	srcs/child.c	\
		srcs/main.c	\
		srcs/pipex.c	\
		srcs/utils.c	\
		libft/ft_bzero.c	\
		libft/ft_split.c	\
		libft/ft_strlen.c	\
		libft/ft_strjoin.c	\
		libft/ft_strncmp.c	\
		libft/ft_substr.c	\
		libft/ft_strdup.c	\
		libft/ft_putstr_fd.c	\

NAME = pipex

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

re: clean all

.PHONY: clean re all
