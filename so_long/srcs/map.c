/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:17 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/20 12:21:03 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_raw_map(t_map *map, char *filename)
{
	int	fd;
	int	height;

	height = 0;
	fd = open(filename, O_RDONLY);
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

void	draw_map(t_game *game, int x, int y, t_sprite *sprite)
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
}

void	init_map(t_game *game, char *filename)
{
	int	x;
	int	y;

	add_raw_map(&game->map, filename);
	game->map.grass = init_sprite(game, "./images/grass.xpm", 32, 32);
	if (!game->map.grass)
		exit_game(game, "Grass sprite init failed\n");
	game->map.mountain = init_sprite(game, "./images/mountain.xpm", 32, 32);
	if (!game->map.mountain)
		exit_game(game, "Mountain sprite init failed\n");
	game->map.exit = init_sprite(game, "./images/exit.xpm", 32, 32);
	if (!game->map.exit)
		exit_game(game, "Exit sprite init failed\n");
	game->map.collectible = init_sprite(game, "./images/alert.xpm", 32, 32);
	if (!game->map.collectible)
		exit_game(game, "Coll. sprite init failed\n");
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			if (game->map.raw_map[y][x] == '0' || game->map.raw_map[y][x] == 'C' || game->map.raw_map[y][x] == 'P')
				draw_map(game, x, y, game->map.grass);
			else if (game->map.raw_map[y][x] == '1')
				draw_map(game, x, y, game->map.mountain);
			else if (game->map.raw_map[y][x] == 'E')
				draw_map(game, x, y, game->map.exit);
			x++;
		}
		y++;
	}
}
