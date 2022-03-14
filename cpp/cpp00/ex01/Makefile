#!/bin/bash

SRCS =	main.cpp			\
		PhoneBook.cpp		\
		Contact.cpp			\

OBJS = $(SRCS:.cpp=.o)

NAME = phonebook

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
