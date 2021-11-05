/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:06 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/05 14:01:04 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_player *init_player(t_game *game)
{
	t_player *player;

	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->sprite = init_sprite(game, "./images/player.xpm", player->width, player->height);
	player->collectibles = 0;
	game->player = player;
	return (player);
}

int check_tile(t_game *game, int move)
{
	// if (move == UP && \
	// 	game->map->raw_map[game->player->sprite->y - 1][game->player->sprite->x] == '1')
	// 	{
	// 		printf("AFTER CHECK : %d %d\n",  game->player->sprite->y,  game->player->sprite->x);
	// 		return (0);
	// 	}
	// else if (move == DOWN && \
	// 	game->map->raw_map[game->player->sprite->y + 1][game->player->sprite->x] == '1')
	// 	return (0);
	// else if (move == LEFT && \
	// 	game->map->raw_map[game->player->sprite->y][game->player->sprite->x - 1] == '1')
	// 	return (0);
	// else if (move == RIGHT && \
	// 	game->map->raw_map[game->player->sprite->y][game->player->sprite->x + 1] == '1')
	// 	return (0);
	return (1);
}

void move_player(int kc, t_game *game)
{
	if (kc == UP && check_tile(game, UP))
	{
		printf("MOVE : %d %d\n",  game->player->sprite->y - 1,  game->player->sprite->x);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x * TILE_WIDTH, game->player->sprite->y-- * TILE_HEIGHT);
	}
	else if (kc == DOWN && check_tile(game, DOWN))
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x * TILE_WIDTH, game->player->sprite->y++ * TILE_HEIGHT);
	else if (kc == LEFT && check_tile(game, LEFT))
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x-- * TILE_WIDTH, game->player->sprite->y * TILE_HEIGHT);
	else if (kc == RIGHT && check_tile(game, RIGHT))
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x++ * TILE_WIDTH, game->player->sprite->y * TILE_HEIGHT);
}
