#!/bin/bash

SRCS =	main.cpp		\
		ScalarConverter.cpp	\

INCS = 	ScalarConverter.hpp	\

OBJS = $(SRCS:.cpp=.o)

NAME = convert

RM = rm -f

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
