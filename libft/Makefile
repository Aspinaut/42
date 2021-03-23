#!/bin/bash

DIR = .

INCLUDES = -Iincludes

SRCS = ${DIR}/$(wildcard *.c)

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
