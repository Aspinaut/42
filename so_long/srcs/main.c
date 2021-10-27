/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:31 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/27 12:41:08 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_player(int kc, t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (kc == UP)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img_ptr, game->img->x, game->img->y--);
	else if (kc == DOWN)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img_ptr, game->img->x, game->img->y++);
	else if (kc == LEFT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img_ptr, game->img->x--, game->img->y);
	else if (kc == RIGHT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img->img_ptr, game->img->x++, game->img->y);
}

int process_key_hook(int kc, t_game *game)
{
	// printf("%d\n", kc);
	if (kc == ESCAPE)
		return (mlx_loop_end(game->mlx_ptr));
	else if (kc == UP || kc == DOWN || kc == LEFT || kc == RIGHT)
		move_player(kc, game);
	return (1);
}

int main(void)
{
    t_game        game;
	t_img			img;

	game.mlx_ptr = mlx_init();
    if (game.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Hello world");
    if (!game.win_ptr)
		return (EXIT_FAILURE);

	// img.img_ptr = mlx_new_image(game.mlx_ptr, 40, 40);
	// img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.size_line, &img.endian);

	img.path = "/home/vmasse/Code/42/so_long/images/ralph.xpm";
	img.width = 50;
	img.height = 35;
	img.y = 0;
	img.x = 0;
	img.img_ptr = mlx_xpm_file_to_image(game.mlx_ptr, img.path, &img.width, &img.height);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img.img_ptr, img.x, img.y);

	game.img = &img;
	// while (img.x < WIN_WIDTH)
	// {
	// 	mlx_clear_window(game.mlx_ptr, game.win_ptr);
	// 	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, img.img_ptr, img.x, img.y);
	// 	if (img.x + 1 == WIN_WIDTH)
	// 		img.x = 0;
	// 	img.x++;
	// }

	mlx_key_hook(game.win_ptr, process_key_hook, &game);
	// int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
	// int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);

	mlx_loop(game.mlx_ptr);
    return (EXIT_SUCCESS);
}
