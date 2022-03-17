#!/bin/bash

SRCS =	tests.cpp		\
		Account.cpp		

OBJS = $(SRCS:.cpp=.o)

NAME = accounts

RM = rm -f

CC = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
