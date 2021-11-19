/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/19 15:49:37 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(t_game *game, char *msg)
{
	ft_putstr_fd(msg, 2);
	if (!game)
		exit(EXIT_FAILURE);
	ft_free(game);
	exit(EXIT_SUCCESS);
}

void	ft_free(t_game *game)
{
	int			i;

	i = 0;
	while (game->map.raw_map[i])
	{
		free(game->map.raw_map[i++]);
	}
	free(game->map.raw_map);
	free(game->map.mountain);
	free(game->map.grass);
	free(game->map.exit);
	free(game->map.collectible);
	free(game->player.sprite);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
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
	exit_game(&game, "Turning off...\n");
	return (0);
}
