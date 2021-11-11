/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:20:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/11 16:15:20 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_moves(t_game *game)
{
	write(1, ft_itoa(++(game->player.moves)),
		ft_strlen(ft_itoa(game->player.moves)));
	write(1, "\n", 1);
}
