/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/21 12:43:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_free(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.raw_map[i])
		free(game->map.raw_map[i++]);
	free(game->map.raw_map);
	mlx_destroy_image(game->mlx_ptr, game->map.mountain->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->map.grass->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->map.exit->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->map.collectible->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.sprite->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->map.enemy1->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->map.enemy2->img_ptr);
	free(game->player.sprite);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free(game->mlx_ptr);
	game->win_ptr = NULL;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_game(NULL, "Wrong nb of args, try ./so_long your_map.ber\n");
	if (!check_map(argv[1]))
		exit_game(NULL, "something wrong in the map\n");
	init_game(&game, argv[1]);
	mlx_hook(game.win_ptr, 2, 1L << 0, process_key_hook, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.mlx_ptr, start_game, &game);
	mlx_loop(game.mlx_ptr);
	exit_game(&game, "Turning off...\n");
	return (0);
}
