/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:17 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/02 12:00:37 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_map()
{
	return (1);
}

t_map *init_map(t_game *game)
{
	int raw_map[5][5] = {
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
	};
	t_map *map;
	int x;
	int y;
	// remplacer 5 par map_width et map_height
	int width =  5;
	int height = 5;

	map = (t_map *)malloc(sizeof(t_map));
	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			if (raw_map[x][y] == 1)
			{
				map->sprite = init_sprite(game, "/home/vmasse/Code/42/so_long/images/blood.xpm", 1111, 1111);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
				map->sprite = map->sprite->next;
			}
			else if (raw_map[x][y] == 0)
			{
				map->sprite = init_sprite(game, "/home/vmasse/Code/42/so_long/images/alert.xpm", 1111, 1111);
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, map->sprite->img_ptr, TILE_WIDTH * x, TILE_HEIGHT * y);
				map->sprite = map->sprite->next;
			}
			y++;
		}
		x++;
	}
	game->map = map;
	return (map);
}
