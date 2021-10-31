/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/31 08:13:01 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
    t_game        	*game;
	t_map			*map;
	// t_player		*player;

	if (!check_map())
		return (EXIT_FAILURE);
	game = init_game();
	if (!game)
		return (EXIT_FAILURE);
	map = init_map(&game);
	// player = init_player(&game);
	// mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, player->sprite->img_ptr, player->sprite->x, player->sprite->y);
	(void)map;
	mlx_hook(game->win_ptr, 2, 1L<<0, process_key_hook, game);
	mlx_loop(game->mlx_ptr);
    return (EXIT_SUCCESS);
}
