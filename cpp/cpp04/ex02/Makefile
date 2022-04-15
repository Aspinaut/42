#!/bin/bash

SRCS =	main.cpp		\
		AAnimal.cpp		\
		Dog.cpp		\
		Cat.cpp		\
		WrongAnimal.cpp		\
		WrongCat.cpp		\
		Brain.cpp		\

INCS = 	AAnimal.hpp	\
		Dog.hpp		\
		Cat.hpp		\
		WrongAnimal.hpp		\
		WrongCat.hpp		\
		Brain.hpp		\

OBJS = $(SRCS:.cpp=.o)

NAME = animals

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
