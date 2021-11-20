/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:20:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/20 12:22:31 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves(t_game *game)
{
	char *moves;
	char *count;

	game->player.moves++;
	count = ft_itoa(game->player.moves);
	if (!count)
		return ;
	moves = ft_strjoin("Moves : ", count);
	if (!moves)
		return ;
	write(1, moves, ft_strlen(moves));
	write(1, "\n", 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->map.mountain->img_ptr, TILE_WIDTH * 1, TILE_HEIGHT * 0);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->map.mountain->img_ptr, TILE_WIDTH * 2, TILE_HEIGHT * 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 0x00FF0000, moves);
	free(moves);
	free(count);
}
