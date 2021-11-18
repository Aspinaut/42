/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:20:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/18 10:43:31 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves(t_game *game)
{
	char *moves;

	game->player.moves++;
	moves = ft_strjoin("Moves : ", ft_itoa(game->player.moves));
	if (!moves)
		return ;
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	game->map.sprite = game->map.sprite->next;
	game->map.sprite = init_sprite(game,
			"./images/mountain.xpm", 32, 32);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->map.sprite->img_ptr, TILE_WIDTH * 1, TILE_HEIGHT * 0);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->map.sprite->img_ptr, TILE_WIDTH * 2, TILE_HEIGHT * 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0x00FF0000, moves);
	free(moves);
}
