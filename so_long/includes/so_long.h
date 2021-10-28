/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:24:37 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/28 11:36:11 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define WIN_WIDTH 	1600
# define WIN_HEIGHT 1200

# define UP 		65362
# define DOWN 		65364
# define LEFT 		65361
# define RIGHT 		65363
# define ESCAPE 	65307

typedef struct    s_img
{
	void 			*img_ptr;
	char 			*addr;
	char			*path;
	int 			x;
	int				y;
	int 			width;
	int				height;
	int 			*bits_per_pixel;
	int 			*size_line;
	int 			*endian;
	struct s_img 	*prev;
	struct s_img 	*next;
}                 t_img;

typedef struct    s_player
{
	struct s_img	*img;
}                 t_player;

typedef struct    s_game
{
    void			*mlx_ptr;
    void			*win_ptr;
	struct s_img	*img;
	struct s_player	*player;
}                 t_game;

/* HOOKS */

int process_key_hook(int keycode, t_game *game);

/* PLAYER */

void move_player(int kc, t_game *game);

/* SPRITES */

t_img *init_img(t_game *game, char *path, int width, int height);

/* MAP */


/* GAME */

t_game *init_game();

#endif
