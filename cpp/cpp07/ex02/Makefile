#!/bin/bash

SRCS =	main.cpp		\

INCS = 	Array.hpp	\

OBJS = $(SRCS:.cpp=.o)

NAME = array

RM = rm -f

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
