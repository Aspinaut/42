/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:06:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/20 12:20:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_sprite	*init_sprite(t_game *game, char *path, int width, int height)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		exit_game(game, "Sprite malloc failed...\n");
	sprite->x = 0;
	sprite->y = 0;
	sprite->path = path;
	sprite->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			sprite->path, &width, &height);
	if (!sprite->img_ptr)
		exit_game(game, "Sprite creation failed...\n");
	return (sprite);
}
