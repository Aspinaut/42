/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:04:56 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/05 15:05:56 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	process_key_hook(int kc, t_game *game)
{
	// printf("%d\n", kc);
	if (kc == ESCAPE)
		return (0);
		// exit(mlx_loop_end(game->mlx_ptr));
	else if (kc == UP || kc == DOWN || kc == LEFT || kc == RIGHT)
		move_player(kc, game);
	return (1);
}
