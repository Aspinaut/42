/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:06:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/27 18:33:37 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img *init_img(t_game *game, char *path, int width, int height)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->x = 0;
	img->y = 0;
	img->path = path;
	img->width = width;
	img->height = height;
	img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, img->path, img->width, img->height);
	img->next = NULL;
	return (img);
}
