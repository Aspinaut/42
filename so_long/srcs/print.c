/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:20:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/12 10:44:27 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves(t_game *game)
{
	game->player.moves++;
	write(1, ft_itoa(game->player.moves),
		ft_strlen(ft_itoa(game->player.moves)));
	write(1, "\n", 1);
}
