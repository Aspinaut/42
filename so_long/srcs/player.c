/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:06 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/20 12:21:18 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_player(t_game *game)
{
	game->player.sprite = init_sprite(game, "./images/player.xpm",
			game->player.width, game->player.height);
	if (!game->player.sprite)
		exit_game(game, "Player sprite failed to init...\n");
	game->player.collectibles = 0;
	game->player.moves = -1;
}

void	check_collectibles(t_game *game, int move)
{
	if (game->player.collectibles == game->collectibles)
	{
		if ((move == UP
				&& game->map.raw_map[game->player.sprite->y - 1]
				[game->player.sprite->x] == 'E')
			|| (move == DOWN
				&& game->map.raw_map[game->player.sprite->y + 1]
				[game->player.sprite->x] == 'E')
			|| (move == LEFT
				&& game->map.raw_map[game->player.sprite->y]
				[game->player.sprite->x - 1] == 'E')
			|| (move == RIGHT
				&& game->map.raw_map[game->player.sprite->y]
				[game->player.sprite->x + 1] == 'E'))
		{
			print_moves(game);
			exit_game(game, "WELL PLAYED !\n");
		}
	}
}

int	check_next_tile(t_game *game, int move)
{
	if (move == UP
		&& game->map.raw_map[game->player.sprite->y - 1]
		[game->player.sprite->x] == '1')
		return (0);
	else if (move == DOWN
		&& game->map.raw_map[game->player.sprite->y + 1]
		[game->player.sprite->x] == '1')
		return (0);
	else if (move == LEFT
		&& game->map.raw_map[game->player.sprite->y]
		[game->player.sprite->x - 1] == '1')
		return (0);
	else if (move == RIGHT
		&& game->map.raw_map[game->player.sprite->y]
		[game->player.sprite->x + 1] == '1')
		return (0);
	check_collectibles(game, move);
	return (1);
}

void	update_background(t_game *game)
{
	t_sprite	*sprite;

	if (game->map.raw_map[game->player.sprite->y]
		[game->player.sprite->x] == '0'
		|| game->map.raw_map[game->player.sprite->y]
		[game->player.sprite->x] == 'P')
		sprite = game->map.grass;
	else if (game->map.raw_map[game->player.sprite->y]
		[game->player.sprite->x] == 'E')
		sprite = game->map.exit;
	else if (game->map.raw_map[game->player.sprite->y]
		[game->player.sprite->x] == 'C')
	{
		sprite = game->map.grass;
		game->map.raw_map[game->player.sprite->y][game->player.sprite->x] = '0';
		game->player.collectibles++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		sprite->img_ptr, game->player.sprite->x * TILE_WIDTH,
		game->player.sprite->y * TILE_HEIGHT);
}

void	move_player(int kc, t_game *game)
{
	update_background(game);
	if (kc == UP && check_next_tile(game, UP))
		game->player.sprite->y--;
	else if (kc == DOWN && check_next_tile(game, DOWN))
		game->player.sprite->y++;
	else if (kc == LEFT && check_next_tile(game, LEFT))
		game->player.sprite->x--;
	else if (kc == RIGHT && check_next_tile(game, RIGHT))
		game->player.sprite->x++;
	else
		return ;
	print_moves(game);
}
