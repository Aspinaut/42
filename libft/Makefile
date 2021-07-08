#!/bin/bash

DIR = .

INCLUDES = -Iincludes

SRCS =	ft_isdigit.c	\
		ft_lstmap.c	\
		ft_memmove.c	\
		ft_putstr_fd.c	\
		ft_striter.c	\
		ft_strncmp.c	\
		ft_tolower.c	\
		ft_isprint.c	\
		ft_lstnew.c	\
		ft_memset.c	\
		ft_split.c	\
		ft_striteri.c	\
		ft_strncpy.c	\
		ft_toupper.c	\
		ft_itoa.c	\
		ft_lstsize.c	\
		ft_putchar.c	\
		ft_strcat.c	\
		ft_strjoin.c	\
		ft_strnequ.c	\
		ft_atoi.c	\
		ft_lstadd_back.c	\
		ft_memalloc.c	\
		ft_putchar_fd.c	\
		ft_strchr.c	\
		ft_strlcat.c	\
		ft_strnew.c	\
		ft_bzero.c	\
		ft_lstadd_front.c	\
		ft_memccpy.c	\
		ft_putendl.c	\
		ft_strclr.c	\
		ft_strlcpy.c	\
		ft_strnstr.c	\
		ft_calloc.c	\
		ft_lstclear.c	\
		ft_memchr.c	\
		ft_putendl_fd.c	\
		ft_strcpy.c	\
		ft_strlen.c	\
		ft_strrchr.c	\
		ft_isalnum.c	\
		ft_lstdelone.c	\
		ft_memcmp.c	\
		ft_putnbr.c	\
		ft_strdel.c	\
		ft_strmap.c	\
		ft_strstr.c	\
		ft_isalpha.c	\
		ft_lstiter.c	\
		ft_memcpy.c	\
		ft_putnbr_fd.c	\
		ft_strdup.c	\
		ft_strmapi.c	\
		ft_strtrim.c	\
		ft_isascii.c	\
		ft_lstlast.c	\
		ft_memdel.c	\
		ft_putstr.c	\
		ft_strequ.c	\
		ft_strncat.c	\
		ft_substr.c	\

OBJS = ${SRCS:.c=.o}

NAMEA = libft.a

NAMESO = libft.so

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} ${INCLUDES} -c $< -o ${<:.c=.o}


${NAMEA}: ${OBJS}
		ar crs ${NAMEA} ${OBJS}
		${RM} ${OBJS}

so:
	${CC} ${CFLAGS} ${INCLUDES} -fPIC -c ${SRCS}
	${CC} -shared -Wl,-soname,${NAMESO} -o ${NAMESO} ${OBJS}

all: ${NAMEA}

clean:
	${RM} ${OBJS}

fclean: clean
							${RM} ${NAMEA}

re: fclean all
