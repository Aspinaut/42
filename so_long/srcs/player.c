/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:06 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/07 09:51:53 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_player	*init_player(t_game *game)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->sprite = init_sprite(game, "./images/player.xpm",
		player->width, player->height);
	player->collectibles = 0;
	game->player = player;
	return (player);
}

int	check_next_tile(t_game *game, int move)
{
	if (move == UP && \
		game->map->raw_map[game->player->sprite->y - 1][\
			game->player->sprite->x] == '1')
				return (0);
	else if (move == DOWN && \
		game->map->raw_map[game->player->sprite->y + 1][\
			game->player->sprite->x] == '1')
				return (0);
	else if (move == LEFT && \
		game->map->raw_map[game->player->sprite->y][\
			game->player->sprite->x - 1] == '1')
				return (0);
	else if (move == RIGHT && \
		game->map->raw_map[game->player->sprite->y][\
			game->player->sprite->x + 1] == '1')
				return (0);
	return (1);
}

void	save_current_tile(t_game *game)
{
	(void)game;
}

void move_player(int kc, t_game *game)
{
	if (kc == UP && check_next_tile(game, UP))
	{
		game->player->sprite->y--;

	}
	else if (kc == DOWN && check_next_tile(game, DOWN))
	{
		game->player->sprite->y++;

	}
	else if (kc == LEFT && check_next_tile(game, LEFT))
	{
		game->player->sprite->x--;

	}
	else if (kc == RIGHT && check_next_tile(game, RIGHT))
	{
		game->player->sprite->x++;

	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->player->sprite->img_ptr, game->player->sprite->x * TILE_WIDTH,
		game->player->sprite->y * TILE_HEIGHT);
}
