/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:17 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/04 13:55:18 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_map(char *filename)
{
	int fd;
	char *s;

	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	while (s && s[0])
	{
		// printf("|%s", s);
		free(s);
		s = get_next_line(fd);
	}
	// printf("|%s", s);
	free(s);
	close(fd);
	return (1);
}

void add_raw_map(t_map *map, char *filename)
{
	int fd;
	int height;

	height = 0;
	fd = open(filename, O_RDONLY);
	// remplacer 1000 par ???
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

t_map *init_map(t_game *game, char *filename)
{
	t_map *map;
	int x;
	int y;

	map = (t_map *)malloc(sizeof(t_map));
	add_raw_map(map, filename);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->raw_map[y][x] == '1')
			{
				map->sprite = init_sprite(game, "./images/mountain.xpm", 32, 32);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
				// map->sprite = map->sprite->next;
			}
			else if (map->raw_map[y][x] == '0')
			{
				map->sprite = init_sprite(game, "./images/grass.xpm", 32, 32);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
				// map->sprite = map->sprite->next;
			}
			else if (map->raw_map[y][x] == 'E')
			{
				map->sprite = init_sprite(game, "./images/exit.xpm", 32, 32);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
				// map->sprite = map->sprite->next;
			}
			else if (map->raw_map[y][x] == 'C')
			{
				map->sprite = init_sprite(game, "./images/grass.xpm", 32, 32);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
				// segfault !!
				// game->collectible->pos[0] = y;
				// game->collectible->pos[1] = x;
				// map->sprite = map->sprite->next;
			}
			else if (map->raw_map[y][x] == 'P')
			{
				map->sprite = init_sprite(game, "./images/grass.xpm", 32, 32);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
				game->player->sprite->y = y;
				game->player->sprite->x = x;
				// map->sprite = map->sprite->next;
			}
			x++;
		}
		y++;
	}
	game->map = map;
	return (map);
}
