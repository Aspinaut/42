/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/30 13:39:40 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
    t_game        	*game;
	t_sprite			*sprite;
	t_map			*map;

	if (!check_map())
		return (EXIT_FAILURE);
	game = init_game();
	if (!game)
		return (EXIT_FAILURE);
	map = init_map(&game);
	sprite = init_sprite(game, "/home/vmasse/Code/42/so_long/images/ralph.xpm", 50, 80);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, sprite->img_ptr, sprite->x, sprite->y);
	mlx_hook(game->win_ptr, 2, 1L<<0, process_key_hook, game);
	mlx_loop(game->mlx_ptr);
    return (EXIT_SUCCESS);
}
