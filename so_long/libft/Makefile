#!/bin/bash

SRCS =	ft_atoi.c	\
		ft_atol.c	\
		ft_isdigit.c	\
		ft_putstr_fd.c	\
		ft_split.c	\

OBJS = $(SRCS:.c=.o)

NAME = libft.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
