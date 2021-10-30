/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:06:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/30 13:10:10 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void last_sprite(t_game **game)
{
	while ((*game)->sprite && (*game)->sprite->next)
		(*game)->sprite = (*game)->sprite->next;
}

void rewind_sprites(t_game **game)
{
	while ((*game)->sprite && (*game)->sprite->prev)
		(*game)->sprite = (*game)->sprite->prev;
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
	sprite->width = width;
	sprite->height = height;
	sprite->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, sprite->path, &sprite->width, &sprite->height);
	sprite->next = NULL;
	if (!game->sprite)
	{
		sprite->prev = NULL;
		game->sprite = sprite;
	}
	else
	{
		last_sprite(&game);
		sprite->prev = game->sprite;
		game->sprite->next = sprite;
		rewind_sprites(&game);
	}
	return (sprite);
}
