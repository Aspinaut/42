#!/bin/bash

SRCS =	srcs/main.c	\


LIBFT = libft/libft.a

MLX = mlx/libmlx.a

NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(SRCS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit -L./libft -lft -o $(NAME)

#linux : -lmlx -lXext -lX11
# Mac : -framework OpenGL -framework AppKit

#$(MLX_OBJS)
#	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(MLX): $(MLX_OBJS)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(MLX)

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	cd ./libft/ && make clean && cd ../mlx/ && make clean && cd ..

fclean:
	cd ./libft/ && make fclean && cd ../mlx/ && make clean && cd ..
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
