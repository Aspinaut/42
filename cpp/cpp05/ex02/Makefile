#!/bin/bash

SRCS =	main.cpp		\
		Bureaucrat.cpp	\
		AForm.cpp		\
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \

INCS = 	Bureaucrat.hpp	\
		AForm.hpp		\
		ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp \

OBJS = $(SRCS:.cpp=.o)

NAME = Bureaucrat

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
