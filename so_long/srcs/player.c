/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:06 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/30 13:11:08 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void move_player(int kc, t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	if (kc == UP)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprite->img_ptr, game->sprite->x, game->sprite->y--);
	else if (kc == DOWN)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprite->img_ptr, game->sprite->x, game->sprite->y++);
	else if (kc == LEFT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprite->img_ptr, game->sprite->x--, game->sprite->y);
	else if (kc == RIGHT)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->sprite->img_ptr, game->sprite->x++, game->sprite->y);
}
