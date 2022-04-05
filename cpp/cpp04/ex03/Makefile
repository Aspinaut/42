#!/bin/bash

SRCS =	main.cpp		\
		AMateria.cpp	\

INCS = 	AMateria.hpp	\

OBJS = $(SRCS:.cpp=.o)

NAME = AMateria

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
