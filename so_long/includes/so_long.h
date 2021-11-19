/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:24:37 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/19 16:33:49 by vmasse           ###   ########.fr       */
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
# define ESCAPE 	65307

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
	// struct s_sprite		*prev;
	// struct s_sprite		*next;
}						t_sprite;

typedef struct s_map
{
	int				width;
	int				height;
	/* attentio à free à la fin !!!!! */
	char			**raw_map;
	t_sprite		*grass;
	t_sprite		*exit;
	t_sprite		*mountain;
	t_sprite		*collectible;
	// t_sprite		*sprite;
}					t_map;

typedef struct s_player
{
	int				width;
	int				height;
	int				collectibles;
	int				moves;
	t_sprite		*sprite;
}					t_player;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_width;
	int				win_height;
	int				collectibles;
	t_player		player;
	t_map			map;
	// t_sprite		*sprites;
}					t_game;

/* HOOKS */

int			process_key_hook(int keycode, t_game *game);
int			close_window(t_game *game);

/* PLAYER */

void 		init_player(t_game *game);
void		check_collectibles(t_game *game, int move);
int			check_next_tile(t_game *game, int move);
void		move_player(int kc, t_game *game);

/* SPRITES */

t_sprite	*init_sprite(t_game *game, char *path, int width, int height);
void		last_sprite(t_game *game);
void		rewind_sprites(t_game *game);

/* MAP */

void		init_map(t_game *game, char *filename);
void		add_raw_map(t_map *map, char *filename);
// char		*tile_char_to_path(char tile);
void		draw_map(t_game *game, int x, int y, t_sprite *sprite);

/* GAME */

void		set_window_size(t_game *game, char *filename);
void		init_game(t_game *game, char *filename);
int			start_game(t_game	*game);

/* CHECK_UTILS */

int			check_walls(char *s);
int			check_used(char *is_used, char c);
int			check_other_chars(char *s);
char		*check_letters(char *s, char *tab, int *i);
int			str_free(int ret, char *s1, char *s2, char *s3);

/* CHECK */

int			check_map(char *filename);
int			check_lines_map(int fd, char *s, int len);
int			init_check_map_vars(char **is_used, char **s_buff, int *i);

/* PRINT */

void		print_moves(t_game *game);

void	exit_game(t_game *game, char *msg);
void	ft_free(t_game *game);

#endif
