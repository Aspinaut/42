#!/bin/bash

SRCS =	srcs/main.c		\
		srcs/player.c	\
		srcs/map.c		\
		srcs/hooks.c		\
		srcs/sprites.c		\
		srcs/game.c		\
		get_next_line/get_next_line.c		\
		get_next_line/get_next_line_utils.c		\

LIBFT = libft/libft.a

MLX = mlx/libmlx.a

NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

#linux : -lmlx -lXext -lX11
# Mac : -framework OpenGL -framework AppKit

MLXFLAG = -framework OpenGL -framework AppKit

$(NAME): $(LIBFT) $(MLX) $(SRCS)
	$(CC) -fsanitize=address $(CFLAGS) $(SRCS) $(MLXFLAG) $(MLX) -L./mlx -L./libft -lft -o $(NAME)

all: $(NAME)

$(MLX):
	$(MAKE) -C ./mlx

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	cd ./libft/ && make clean && cd ../mlx/ && make clean && cd ..

fclean:
	cd ./libft/ && make fclean && cd ../mlx/ && make clean && cd ..
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
