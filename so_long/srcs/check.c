/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:50:48 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/11 16:53:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_used(char *is_used, char c)
{
	int	i;

	i = 0;
	while (is_used && is_used[i])
	{
		if (is_used[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_other_chars(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] != '0' && s[i] != '1'
		&& s[i] != 'E' && s[i] != 'P' && s[i] != 'C')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(char *filename)
{
	char	*s;
	char	*s_buff;
	char	is_used[3];
	int		i;
	int		fd;
	int		len;

	// pas oublier de free et return "Error..." !!!
	if (ft_strncmp((filename + ft_strlen(filename) - 4), ".ber", 4))
		return (0);
	fd = open(filename, O_RDONLY);
	s = get_next_line(fd);
	len = ft_strlen(s);
	if (!s)
		return (0);
	if (!check_walls(s))
		return (0);
	i = 0;
	while (s && s[0])
	{
		if (ft_strchr(s, 'E') && !check_used(is_used, 'E'))
			is_used[i++] = 'E';
		if (ft_strchr(s, 'P') && !check_used(is_used, 'P'))
			is_used[i++] = 'P';
		if (ft_strchr(s, 'C') && !check_used(is_used, 'C'))
			is_used[i++] = 'C';
		if ((s[0] && s[ft_strlen(s) - 2] != '1') || !check_other_chars(s))
			return (0);
		s = get_next_line(fd);
		if (s)
		{
			s_buff = ft_strdup(s);
			if (!s_buff || ft_strlen(s_buff) != len)
				return (0);
		}
	}
	if (!check_walls(s_buff))
		return (0);
	if (!check_used(is_used, 'E') || !check_used(is_used, 'P') ||
		!check_used(is_used, 'C'))
		return (0);
	free(s);
	free(s_buff);
	close(fd);
	return (1);
}
