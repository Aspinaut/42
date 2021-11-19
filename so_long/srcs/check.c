/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:50:48 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/19 11:02:52 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	final_check(char *s_buff, char *is_used)
{
	if (!check_walls(s_buff) || !check_used(is_used, 'E')
		|| !check_used(is_used, 'P') || !check_used(is_used, 'C'))
		return (0);
	return (1);
}

int	init_check_map_vars(char **is_used, char **s_buff, int *i)
{
	*i = 0;
	*s_buff = NULL;
	*is_used = ft_calloc(3, sizeof(char));
	if (!is_used)
		return (0);
	return (1);
}

int	check_lines_map(int fd, char *s, int len)
{
	char	*is_used;
	char	*s_buff;
	int		i;

	if (!init_check_map_vars(&is_used, &s_buff, &i))
		return (0);
	while (s && s[0])
	{
		is_used = check_letters(s, is_used, &i);
		if ((s[0] && s[ft_strlen(s) - 2] != '1') || !check_other_chars(s))
			return (str_free(fd, is_used, s_buff, s));
		free(s);
		s = get_next_line(fd);
		if (s)
		{
			if (s_buff)
				free(s_buff);
			s_buff = ft_strdup(s);
			if (!s_buff || ft_strlen(s_buff) != len)
				return (str_free(fd, is_used, s_buff, s));
		}
	}
	if (!final_check(s_buff, is_used))
		return (str_free(0, is_used, s_buff, s));
	return (str_free(1, is_used, s_buff, s));
}

int	check_map(char *filename)
{
	char	*s;
	int		fd;
	int		len;

	if (ft_strncmp((filename + ft_strlen(filename) - 4), ".ber", 4))
		return (0);
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (0);
	s = get_next_line(fd);
	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!check_walls(s))
		return (str_free(fd, NULL, NULL, s));
	if (!check_lines_map(fd, s, len))
		return (0);
	close(fd);
	return (1);
}
