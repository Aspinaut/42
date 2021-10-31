/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:06 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/31 08:03:35 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_player *init_player(t_game **game)
{
	t_player *player;

	player = (t_player *)malloc(sizeof(t_player));
	player->sprite = init_sprite(game, "/home/vmasse/Code/42/so_long/images/ralph.xpm", 32, 32);
	player->collectibles = 0;
	(*game)->player = player;
	return (player);
}

void move_player(int kc, t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (kc == UP)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x, game->player->sprite->y--);
	else if (kc == DOWN)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x, game->player->sprite->y++);
	else if (kc == LEFT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x--, game->player->sprite->y);
	else if (kc == RIGHT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player->sprite->img_ptr, game->player->sprite->x++, game->player->sprite->y);
}
