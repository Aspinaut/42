/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:17 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/12 12:18:05 by vmasse           ###   ########.fr       */
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

char	*tile_char_to_path(char tile)
{
	char	*path;

	path = NULL;
	if (tile == '1')
	{
		path = "./images/mountain.xpm";
	}
	else if (tile == '0' || tile == 'C' || tile == 'P')
	{
		path = "./images/grass.xpm";
	}
	else if (tile == 'E')
	{
		path = "./images/exit.xpm";
	}
	return (path);
}

void	draw_map(t_game *game, int x, int y)
{
	game->map.sprite = init_sprite(game,
			tile_char_to_path(game->map.raw_map[y][x]), 32, 32);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->map.sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
	if (game->map.raw_map[y][x] == 'C')
	{
		game->map.sprite = init_sprite(game,
				"./images/alert.xpm", 32, 32);
		game->collectibles++;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->map.sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
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
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			draw_map(game, x, y);
			x++;
		}
		y++;
	}
}
