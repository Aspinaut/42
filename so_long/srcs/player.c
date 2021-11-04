/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:06 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/04 09:06:01 by vmasse           ###   ########.fr       */
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

void move_player(int kc, t_game *game)
{
	// mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (kc == UP)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x * TILE_WIDTH, game->player->sprite->y-- * TILE_HEIGHT);
	else if (kc == DOWN)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x * TILE_WIDTH, game->player->sprite->y++ * TILE_HEIGHT);
	else if (kc == LEFT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x-- * TILE_WIDTH, game->player->sprite->y * TILE_HEIGHT);
	else if (kc == RIGHT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x++ * TILE_WIDTH, game->player->sprite->y * TILE_HEIGHT);
}
