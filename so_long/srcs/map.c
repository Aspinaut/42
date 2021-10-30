/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:17 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/30 13:44:15 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int check_map()
{
	return (1);
}

t_map *init_map(t_game **game)
{
	int map[5][5] = {
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}
	}
	t_map *map;
	int x;
	int y;
	int width = WIN_WIDTH / 5;
	int height = WIN_HEIGHT / 5;

	map = (t_map *)malloc(sizeof(t_map));
	x = 0;
	while (x < width)
	{

		y = 0;
		while (y < height)
		{
			if (map[x][y] == 1)
			{
				mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr, (*game)->sprite->img_ptr, map->x, game->sprite->y++);

			}
			else if (map[x][y] == 0)
			{

			}
			y++;
		}
		x++;
	}
	(*game)->map = map;
	return (map);
}
