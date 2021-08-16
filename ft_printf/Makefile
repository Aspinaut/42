#!/bin/bash

SRCS =	ft_isdigit.c	\
		ft_memmove.c	\
		ft_putstr_fd.c	\
		ft_strncmp.c	\
		ft_tolower.c	\
		ft_isprint.c	\
		ft_memset.c	\
		ft_split.c	\
		ft_striteri.c	\
		ft_toupper.c	\
		ft_itoa.c	\
		ft_strjoin.c	\
		ft_atoi.c	\
		ft_putchar_fd.c	\
		ft_strchr.c	\
		ft_strlcat.c	\
		ft_bzero.c	\
		ft_memccpy.c	\
		ft_strlcpy.c	\
		ft_strnstr.c	\
		ft_calloc.c	\
		ft_memchr.c	\
		ft_putendl_fd.c	\
		ft_strlen.c	\
		ft_strrchr.c	\
		ft_isalnum.c	\
		ft_memcmp.c	\
		ft_isalpha.c	\
		ft_memcpy.c	\
		ft_putnbr_fd.c	\
		ft_strdup.c	\
		ft_strmapi.c	\
		ft_strtrim.c	\
		ft_isascii.c	\
		ft_substr.c	\

SRCS_BONUS = ft_lstmap.c	\
			ft_lstnew.c	\
			ft_lstsize.c	\
			ft_lstadd_back.c	\
			ft_lstclear.c	\
			ft_lstdelone.c	\
			ft_lstiter.c	\
			ft_lstlast.c	\
			ft_lstadd_front.c	\
			ft_memalloc_bonus.c	\
			ft_memdel_bonus.c	\
			ft_putchar_bonus.c	\
			ft_putendl_bonus.c	\
			ft_putnbr_bonus.c	\
			ft_putstr_bonus.c	\
			ft_strcat_bonus.c	\
			ft_strclr_bonus.c	\
			ft_strcpy_bonus.c	\
			ft_strdel_bonus.c	\
			ft_strequ_bonus.c	\
			ft_striter_bonus.c	\
			ft_strmap_bonus.c	\
			ft_strncat_bonus.c	\
			ft_strncpy_bonus.c	\
			ft_strnequ_bonus.c	\
			ft_strnew_bonus.c	\
			ft_strstr_bonus.c	\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libft.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

all: $(NAME)

bonus: all $(OBJS_BONUS)
	ar -crs $(NAME) $(OBJS_BONUS) 

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus