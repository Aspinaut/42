/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:17 by vmasse            #+#    #+#             */
/*   Updated: 2021/12/07 10:52:27 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_raw_map(t_map *map, char *filename)
{
	int	fd;
	int	height;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (!fd)
		exit_game(NULL, "Failed to open file...\n");
	map->raw_map = (char **)malloc(sizeof(char *) * 1000);
	if (!map->raw_map)
		exit_game(NULL, "Raw map malloc failed...\n");
	map->raw_map[height] = get_next_line(fd);
	while (map->raw_map[height] && map->raw_map[height][0])
	{
		height++;
		map->raw_map[height] = get_next_line(fd);
	}
	close(fd);
	map->height = height;
	map->width = ft_strlen(map->raw_map[0]);
}

void	draw_tile(t_game *game, int x, int y, t_sprite *sprite)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
	if (game->map.raw_map[y][x] == 'C')
	{
		game->collectibles++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->map.collectible->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
	}
	else if (game->map.raw_map[y][x] == 'P')
	{
		game->player.sprite->y = y;
		game->player.sprite->x = x;
	}
	else if (game->map.raw_map[y][x] == 'M')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->map.enemy1->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
		game->map.enemy1->x = x;
		game->map.enemy1->y = y;
		game->map.enemy2->x = x;
		game->map.enemy2->y = y;
	}
}

void	init_map(t_game *game, char *filename)
{
	int	x;
	int	y;

	add_raw_map(&game->map, filename);
	init_all_sprites(game);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			if (game->map.raw_map[y][x] == '0' ||
				game->map.raw_map[y][x] == 'C' ||
				game->map.raw_map[y][x] == 'P' ||
				game->map.raw_map[y][x] == 'M')
				draw_tile(game, x, y, game->map.grass);
			else if (game->map.raw_map[y][x] == '1')
				draw_tile(game, x, y, game->map.mountain);
			else if (game->map.raw_map[y][x] == 'E')
				draw_tile(game, x, y, game->map.exit);
			x++;
		}
		y++;
	}
}

void	update_background(t_game *game)
{
	t_sprite	*sprite;

	sprite = NULL;
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
