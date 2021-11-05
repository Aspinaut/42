/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:06:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/05 09:48:40 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void last_sprite(t_game *game)
{
	while (game->sprites && game->sprites->next)
		game->sprites = game->sprites->next;
}

void rewind_sprites(t_game *game)
{
	while (game->sprites && game->sprites->prev)
		game->sprites = game->sprites->prev;
}

t_sprite *init_sprite(t_game *game, char *path, int width, int height)
{
	t_sprite *sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		return (NULL);
	sprite->x = 0;
	sprite->y = 0;
	sprite->path = path;
	sprite->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, sprite->path, &width, &height);
	sprite->next = NULL;
	// if (!game->sprites)
	// {
	// 	sprite->prev = NULL;
	// 	game->sprites = sprite;
	// }
	// else
	// {
	// 	last_sprite(game);
	// 	sprite->prev = game->sprites;
	// 	game->sprites->next = sprite;
	// 	rewind_sprites(game);
	// }
	return (sprite);
}
