#!/bin/bash

SRCS =	srcs/formats_csp%.c	\
		srcs/formats_diuxX.c	\
		srcs/ft_printf.c	\
		srcs/putnbr.c	\
		srcs/utils.c	\

OBJS = $(SRCS:.c=.o)

NAME = ft_printf.a

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
