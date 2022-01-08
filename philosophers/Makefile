#!/bin/bash

SRCS =	srcs/main.c			\
		srcs/utils.c		\
		srcs/ft_atoi.c		\
		srcs/actions.c		\
		srcs/params.c		\
		srcs/philos.c		\

OBJS = $(SRCS:.c=.o)

NAME = philo

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
