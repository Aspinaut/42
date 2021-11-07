/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:24:37 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/07 09:51:38 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_opengl.h"
# include "./get_next_line.h"
# include "./libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# define TILE_WIDTH 		32
# define TILE_HEIGHT 		32

/* ------------- Linux --------------------------------
*/
# define UP 		65362
# define DOWN 		65364
# define LEFT 		65361
# define RIGHT 		65363
# define ESCAPE 	53

/* ------------- MAC ----------------------------------
# define UP 		126
# define DOWN 		125
# define LEFT 		123
# define RIGHT 		124
# define ESCAPE 	53
*/

typedef struct s_sprite
{
	void				*img_ptr;
	char				*addr;
	char				*path;
	int					x;
	int					y;
	int					width;
	int					height;
	struct s_sprite		*prev;
	struct s_sprite		*next;
}						t_sprite;

typedef struct s_map
{
	int				width;
	int				height;
	/* attentio à free à la fin !!!!! */
	char			**raw_map;
	struct s_sprite	*sprite;
}					t_map;

typedef struct s_coll
{
	struct s_sprite	*sprite;
}					t_coll;

typedef struct s_player
{
	int				width;
	int				height;
	int				collectibles;
	struct s_sprite	*sprite;
}					t_player;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	struct s_sprite	*sprites;
	struct s_player	*player;
	struct s_map	*map;
	struct s_coll	*collectible;
}					t_game;

/* HOOKS */

int			process_key_hook(int keycode, t_game *game);

/* PLAYER */

t_player	*init_player(t_game *game);
void		move_player(int kc, t_game *game);
int			check_next_tile(t_game *game, int move);

/* SPRITES */

t_sprite	*init_sprite(t_game *game, char *path, int width, int height);
void		last_sprite(t_game *game);
void		rewind_sprites(t_game *game);

/* MAP */

int			check_map(char *filename);
t_map		*init_map(t_game *game, char *filename);
void		add_raw_map(t_map *map, char *filename);
int			check_walls(char *s);
int			check_used(char *is_used, char c);
char *tile_char_to_path(char tile);

/* GAME */

void		set_window_size(t_game *game, char *filename);
t_game		*init_game(char *filename);

#endif
