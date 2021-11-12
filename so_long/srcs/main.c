/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/12 12:17:49 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !check_map(argv[1]))
		return (printf("something wrong in the map\n"));
	init_game(&game, argv[1]);
	mlx_hook(game.win_ptr, 2, 1L << 0, process_key_hook, &game);
	mlx_loop_hook(game.mlx_ptr, start_game, &game);
	mlx_loop(game.mlx_ptr);
	return (EXIT_SUCCESS);
}
