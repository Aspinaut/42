/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:34:03 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/28 11:35:13 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_game *init_game()
{
	t_game *game;

	game = (t_game *)malloc(sizeof(t_game));
	game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
		exit(EXIT_FAILURE);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So long");
    if (!game->win_ptr)
		exit(EXIT_FAILURE);
	return (game);
}
