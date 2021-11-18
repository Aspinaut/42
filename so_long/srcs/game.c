/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:34:03 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/15 11:47:29 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_window_size(t_game *game, char *filename)
{
	int		fd;
	char	*s;

	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	game->win_width = ft_strlen(s) - 1;
	game->win_height = 0;
	while (s && s[0])
	{
		game->win_height++;
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
}

void	init_game(t_game *game, char *filename)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		exit(EXIT_FAILURE);
	set_window_size(game, filename);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width * TILE_WIDTH, \
		game->win_height * TILE_HEIGHT, "So long");
	if (!game->win_ptr)
		exit(EXIT_FAILURE);
	game->collectibles = 0;
	init_player(game);
	print_moves(game);
	init_map(game, filename);
}

int start_game(t_game	*game)
{
	if (game->win_ptr)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->player.sprite->img_ptr, game->player.sprite->x * TILE_WIDTH,
			game->player.sprite->y * TILE_HEIGHT);
	}
	return (1);
}
