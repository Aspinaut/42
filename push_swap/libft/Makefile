#!/bin/bash

SRCS =	ft_lstnew.c	\
		ft_lstadd_front.c	\
		ft_lstadd_back.c	\
		ft_lstclear.c	\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstlast.c	\
		ft_lstmap.c	\
		ft_lstsize.c	\

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
