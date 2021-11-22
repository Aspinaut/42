#!/bin/bash

SRCS =	srcs/main.c		\

NAME = philo

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra
CFLAGS += -Werror
CFLAGS += -g

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) srcs/*.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
