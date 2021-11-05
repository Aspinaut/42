/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:17 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/05 16:47:03 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_used(char *is_used, char c)
{
	int i;

	i = 0;
	while (is_used[i])
	{
		if (is_used[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int check_walls(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_map(char *filename)
{
	int fd;
	char *s;
	char *s_buff;
	char is_used[3];
	int i;
	int len;

	(void)is_used;
	// pas oublier de free et return "Error..." !!!
	if (ft_strncmp((filename + ft_strlen(filename) - 4), ".ber", 4))
		return (0);
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	len = ft_strlen(s);
	if (!s)
		return (0);
	if (!check_walls(s))
		return (0);
	i = 0;
	while (s && s[0])
	{
		if (ft_strchr(s, 'E') && !check_used(is_used, 'E'))
			is_used[i++] = 'E';
		if (ft_strchr(s, 'P') && !check_used(is_used, 'P'))
			is_used[i++] = 'P';
		if (ft_strchr(s, 'C') && !check_used(is_used, 'C'))
			is_used[i++] = 'C';
		if (s[0] && s[ft_strlen(s) - 2] != '1')
			return (0);
		s = get_next_line(fd);
		if (s)
		{
			s_buff = ft_strdup(s);
			if (!s_buff || ft_strlen(s_buff) != len)
				return (0);
		}
		// pb = comment protéger gnl ??? a la fin il sera toujours null
	}
	if (!check_walls(s_buff))
		return (0);
	if (!check_used(is_used, 'E') || !check_used(is_used, 'P') \
	 || !check_used(is_used, 'C'))
		return (0);
	free(s);
	free(s_buff);
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
				map->sprite = init_sprite(game, "./images/alert.xpm", 32, 32);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
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
