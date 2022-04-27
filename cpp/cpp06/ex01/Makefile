#!/bin/bash

SRCS =	main.cpp		\
		Data.cpp	\

INCS = 	Data.hpp	\

OBJS = $(SRCS:.cpp=.o)

NAME = data

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
