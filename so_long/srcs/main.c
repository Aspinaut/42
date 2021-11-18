/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/18 12:13:23 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_game *game)
{
	// mlx_destroy_image(game->mlx_ptr, );
	/* code */
	ft_free(game);
	return (0);
}

void	ft_free(t_game *game)
{
	t_sprite	*sprite;
	t_sprite	*player;
	// int			i;

	while (game->map.sprite)
	{
		sprite = game->map.sprite;
		game->map.sprite = game->map.sprite->next;
		free(sprite);
	}
	while (game->player.sprite)
	{
		player = game->player.sprite;
		game->player.sprite = game->player.sprite->next;
		free(player);
	}
	// i = 0;
	// while (game->map.raw_map[i])
	// {
	// 	free(game->map.raw_map[i++]);
	// }
	// free(game->map.raw_map);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !check_map(argv[1]))
		return (printf("something wrong in the map\n"));
	init_game(&game, argv[1]);
	mlx_hook(game.win_ptr, 2, 1L << 0, process_key_hook, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.mlx_ptr, start_game, &game);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
