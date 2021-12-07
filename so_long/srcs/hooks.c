/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:04:56 by vmasse            #+#    #+#             */
/*   Updated: 2021/12/07 10:55:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	process_key_hook(int kc, t_game *game)
{
	if (kc == ESCAPE)
		exit_game(game, "See you :)\n");
	else if (kc == UP || kc == DOWN || kc == LEFT || kc == RIGHT)
		move_player(kc, game);
	return (1);
}

int	close_window(t_game *game)
{
	exit_game(game, "See you :)\n");
	return (1);
}
