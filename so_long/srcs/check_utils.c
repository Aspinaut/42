/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 11:46:43 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/25 12:17:05 by vmasse           ###   ########.fr       */
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
	while (s && s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_other_chars(char *s, char *s_buff, int fd, char *is_used)
{
	int	i;

	i = 0;
	while (s && s[i] != '\n' && s[i] != '\0')
	{
		if (s[i] != '0' && s[i] != '1'
			&& s[i] != 'E' && s[i] != 'P' && s[i] != 'C' && s[i] != 'M')
		{
			str_free(fd, is_used, s_buff, s);
			exit_game(NULL, "Error\nYour map contains unauthorized chars\n");
		}
		i++;
	}
}

char	*check_letters(char *s, char *tab, int *i)
{
	if (ft_strchr(s, 'E') && !check_used(tab, 'E'))
		tab[(*i)++] = 'E';
	if (ft_strchr(s, 'P') && !check_used(tab, 'P'))
		tab[(*i)++] = 'P';
	if (ft_strchr(s, 'C') && !check_used(tab, 'C'))
		tab[(*i)++] = 'C';
	return (tab);
}

int	str_free(int ret, char *s1, char *s2, char *s3)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3 && ret != 1 && ret != 0)
	{
		while (s3)
		{
			free(s3);
			s3 = get_next_line(ret);
		}
		return (0);
	}
	if (s3)
		free(s3);
	return (ret);
}
