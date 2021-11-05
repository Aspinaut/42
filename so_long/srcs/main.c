/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/05 09:42:52 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
    t_game        	*game;
	t_map			*map;
	t_player		*player;
	// int width;
	// int height;

	(void)argc;
	// if (argc != 2 || !check_map(argv[1]))
	// 	return (EXIT_FAILURE);
	game = init_game();
	if (!game)
		return (EXIT_FAILURE);
	player = init_player(game);
	if (!player)
		return (EXIT_FAILURE);
	map = init_map(game, argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, mlx_xpm_file_to_image(game->mlx_ptr, "./images/grass.xpm", &width, &height), 500, 500);
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, mlx_xpm_file_to_image(game->mlx_ptr, "./images/player.xpm", &width, &height), 520, 520);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, player->sprite->img_ptr, game->player->sprite->x * TILE_WIDTH, game->player->sprite->y * TILE_HEIGHT);
	(void)map;
	(void)player;
	mlx_hook(game->win_ptr, 2, 1L<<0, process_key_hook, game);
	mlx_loop(game->mlx_ptr);
    return (EXIT_SUCCESS);
}
