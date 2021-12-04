#!/bin/bash

SRCS =	srcs/main.c		\
		srcs/utils.c		\
		srcs/parsing.c		\

OBJS = $(SRCS:.c=.o)

NAME = philo

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
CFLAGS += -g

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
