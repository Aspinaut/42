/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:06:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/20 14:44:31 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	*init_sprite(t_game *game, char *path, int width, int height)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		exit_game(game, "Sprite malloc failed...\n");
	sprite->x = 0;
	sprite->y = 0;
	sprite->path = path;
	sprite->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			sprite->path, &width, &height);
	if (!sprite->img_ptr)
		exit_game(game, "Sprite creation failed...\n");
	return (sprite);
}

void	init_all_sprites(t_game *game)
{
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
	game->map.enemy1 = init_sprite(game, "./images/enemy1.xpm", 32, 32);
	if (!game->map.enemy1)
		exit_game(game, "Enemy sprite init failed\n");
	game->map.enemy2 = init_sprite(game, "./images/enemy2.xpm", 32, 32);
	if (!game->map.enemy2)
		exit_game(game, "Enemy sprite init failed\n");
}
