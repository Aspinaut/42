#!/bin/bash

SRCS =	main.cpp		\

OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

RM = rm -f

CC = c++

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
