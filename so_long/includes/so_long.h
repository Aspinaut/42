/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:24:37 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/04 09:43:22 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define WIN_WIDTH 	1600
# define WIN_HEIGHT 1200

# define TILE_WIDTH 		32
# define TILE_HEIGHT 		32

# define UP 		65362
# define DOWN 		65364
# define LEFT 		65361
# define RIGHT 		65363
# define ESCAPE 	65307

typedef struct    s_sprite
{
	void 				*img_ptr;
	char 				*addr;
	char				*path;
	int 				x;
	int					y;
	int 				width;
	int					height;
	// int 				*bits_per_pixel;
	// int 				*size_line;
	// int 				*endian;
	struct s_sprite 	*prev;
	struct s_sprite 	*next;
}                 t_sprite;

typedef struct    s_map
{
	int				width;
	int				height;
	// attentio à free à la fin !!!!!
	char			**raw_map;
	struct s_sprite	*sprite;
}                 t_map;

typedef struct    s_coll
{
	struct s_sprite	*sprite;
}                 t_coll;

typedef struct    s_player
{
	int				width;
	int				height;
	int				collectibles;
	struct s_sprite	*sprite;
}                 t_player;

typedef struct    s_game
{
    void			*mlx_ptr;
    void			*win_ptr;
	struct s_sprite	*sprites;
	struct s_player	*player;
	struct s_map	*map;
	struct s_coll	*collectible;
}                 t_game;

/* HOOKS */

int process_key_hook(int keycode, t_game *game);

/* PLAYER */

t_player *init_player(t_game *game);
void move_player(int kc, t_game *game);
int check_tile(t_game *game, int move);

/* SPRITES */

t_sprite *init_sprite(t_game *game, char *path, int width, int height);
void last_sprite(t_game *game);
void rewind_sprites(t_game *game);

/* MAP */

int check_map();
t_map *init_map(t_game *game, char *filename);
void add_raw_map(t_map *map, char *filename);

/* GAME */

t_game *init_game();

#endif
