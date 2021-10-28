/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/28 13:42:11 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
    t_game        	*game;
	t_img			*img;

	game = init_game();
	if (!game)
		return (EXIT_FAILURE);
	img = init_img(game, "/home/vmasse/Code/42/so_long/images/ralph.xpm", 50, 80);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img->img_ptr, img->x, img->y);
	mlx_hook(game->win_ptr, 2, 1L<<0, process_key_hook, game);
	mlx_loop(game->mlx_ptr);
    return (EXIT_SUCCESS);
}
