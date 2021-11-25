/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:50:48 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/25 12:38:33 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	final_check(char *s_buff, char *is_used, char *s)
{
	if (!check_walls(s_buff))
	{
		str_free(0, is_used, s_buff, s);
		exit_game(NULL, "Error\nYour map is not closed\n");
	}
	if (!check_used(is_used, 'E'))
	{
		str_free(0, is_used, s_buff, s);
		exit_game(NULL, "Error\nYour map does not contain any exit\n");
	}
	if (!check_used(is_used, 'P'))
	{
		str_free(0, is_used, s_buff, s);
		exit_game(NULL, "Error\nYour map does not contain any player\n");
	}
	if (!check_used(is_used, 'C'))
	{
		str_free(0, is_used, s_buff, s);
		exit_game(NULL, "Error\nYour map does not contain any collectible\n");
	}
}

void	first_loop_check(char *s, char *s_buff, int fd, char *is_used)
{
	if ((s[0] && s[ft_strlen(s) - 2] != '1'))
	{
		str_free(fd, is_used, s_buff, s);
		exit_game(NULL, "Error\nYour map is not closed\n");
	}
	check_other_chars(s, s_buff, fd, is_used);
	free(s);
}

void	init_check_map_vars(char **is_used, char **s_buff, int fd, char *s)
{
	*s_buff = NULL;
	*is_used = ft_calloc(3, sizeof(char));
	if (!is_used)
	{
		str_free(fd, NULL, NULL, s);
		exit_game(NULL, "Error\nfailed to init check map vars\n");
	}
}

int	check_lines_map(int fd, char *s, int len)
{
	char	*is_used;
	char	*s_buff;
	int		i;

	i = 0;
	init_check_map_vars(&is_used, &s_buff, fd, s);
	while (s && s[0])
	{
		is_used = check_letters(s, is_used, &i);
		first_loop_check(s, s_buff, fd, is_used);
		s = get_next_line(fd);
		if (s)
		{
			if (s_buff)
				free(s_buff);
			s_buff = ft_strdup(s);
			if (!s_buff || ft_strlen(s_buff) != len)
			{
				str_free(fd, is_used, s_buff, s);
				exit_game(NULL, "Error\nYour map is not rectangular\n");
			}
		}
	}
	final_check(s_buff, is_used, s);
	return (str_free(1, is_used, s_buff, s));
}

void	check_map(char *filename)
{
	char	*s;
	int		fd;
	int		len;

	if (ft_strncmp((filename + ft_strlen(filename) - 4), ".ber", 4))
		exit_game(NULL, "Error\nwrong map file extension\n");
	fd = open(filename, O_RDONLY);
	if (!fd)
		exit_game(NULL, "Error\nfailed to open map file\n");
	s = get_next_line(fd);
	if (!s)
		exit_game(NULL, "Error\ngnl failed while checking map\n");
	len = ft_strlen(s);
	if (!check_walls(s))
	{
		str_free(fd, NULL, NULL, s);
		exit_game(NULL, "Error\nYour map is not closed\n");
	}
	check_lines_map(fd, s, len);
	close(fd);
}
