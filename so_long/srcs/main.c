/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/27 18:35:12 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
    t_game        	game;
	t_img			*img;

	game.mlx_ptr = mlx_init();
    if (!game.mlx_ptr)
		exit(EXIT_FAILURE);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So long");
    if (!game.win_ptr)
		exit(EXIT_FAILURE);

	// img.img_ptr = mlx_new_image(game.mlx_ptr, 40, 40);
	// img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);
	img = init_img(&game, "/home/vmasse/Code/42/so_long/images/ralph.xpm", 50, 80);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img->img_ptr, img->x, img->y);

	game.img = img;
	// while (img.x < WIN_WIDTH)
	// {
	// 	mlx_clear_window(game.mlx_ptr, game.win_ptr);
	// 	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img.img_ptr, img.x, img.y);
	// 	if (img.x + 1 == WIN_WIDTH)
	// 		img.x = 0;
	// 	img.x++;
	// }

	// mlx_key_hook(game.win_ptr, process_key_hook, &game);
	mlx_hook(game.win_ptr, 2, 1L<<0, process_key_hook, &game);

	mlx_loop(game.mlx_ptr);
    return (EXIT_SUCCESS);
}
