#!/bin/bash

# linux : -lmlx -lXext -lX11
# Mac : -framework OpenGL -framework AppKit

SRCS =	srcs/main.c		\
		srcs/player.c	\
		srcs/map.c		\
		srcs/hooks.c		\
		srcs/sprites.c		\
		srcs/game.c		\
		srcs/check.c		\
		srcs/check_utils.c		\
		srcs/print.c		\
		get_next_line/get_next_line.c		\
		get_next_line/get_next_line_utils.c		\

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

# ------------  MAC --------------------------------------------------------------------------------------------
# MLX = mlx/libmlx.a
#
# NAME = so_long
#
# RM = rm -f
#
# CC = gcc
#
# CFLAGS = -Wall -Wextra
# CFLAGS += -Werror
# # CFLAGS += -g
# # CFLAGS += -fsanitize=address
#
# MLXFLAG = -framework OpenGL -framework AppKit
#
# $(NAME): $(LIBFT) $(MLX) $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAG) $(MLX) -L./mlx -L./libft -lft -o $(NAME)
#
# all: $(NAME)
#
# $(MLX):
# 	$(MAKE) -C ./mlx
# --------------------------------------------------------------------------------------------------------------

# ------------  LINUX ------------------------------------------------------------------------------------------
MLX = mlx_linux/libmlx_Linux.a

NAME = so_long

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra
CFLAGS += -Werror
# CFLAGS += -g

MLXFLAG = -lmlx -lXext -lX11

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAG) $(MLX) -L./mlx_linux -L./libft -lft -o $(NAME)

all: $(NAME)

$(MLX):
	$(MAKE) -C ./mlx_linux
# --------------------------------------------------------------------------------------------------------------

$(LIBFT):
	$(MAKE) -C ./libft

clean:
	$(RM) $(OBJS) && cd ./libft/ && make clean && cd ../mlx/ && make clean && cd ..

fclean:
	$(RM) $(OBJS) && cd ./libft/ && make fclean && cd ../mlx/ && make clean && cd ..
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
