/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/19 09:58:20 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static	void	ft_free(char *s, char **sta, int fd)
{
	if (sta && fd)
	{
		free(sta[fd]);
		sta[fd] = NULL;
		return ;
	}
	if (s)
		free(s);
	s = NULL;
}

static	char	*return_eof_or_eol(char **s, int fd, char *buffer, int eol)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	if (eol)
	{
		if (s[fd] && ft_strchr_pos(s[fd], '\n') >= 0)
		{
			line = ft_substr(s[fd], 0, ft_strchr_pos(s[fd], '\n') + 1);
			if (!line)
				return (NULL);
			temp = ft_substr(s[fd], ft_strchr_pos(s[fd], '\n') + 1, \
			ft_strlen(s[fd]) + 1);
			if (!temp)
				return (NULL);
			ft_free(*s, s, fd);
			s[fd] = ft_strndup(temp, ft_strlen(temp));
			if (!s[fd])
				return (NULL);
			ft_free(temp, s, 0);
		}
	}
	else
	{
		temp = ft_strndup(s[fd], ft_strlen(s[fd]));
		if (!temp)
			return (NULL);
		ft_free(buffer, s, 0);
		ft_free(*s, s, fd);
		return (temp);
	}
	return (line);
}

static	char	*read_buffer(char **s, int fd, char *buffer, char *line)
{
	char	*temp;

	temp = NULL;
	if (!s[fd])
	{
		s[fd] = ft_strndup(buffer, ft_strlen(buffer));
		if (!s[fd])
			return (NULL);
	}
	else
	{
		temp = ft_strndup(s[fd], ft_strlen(s[fd]));
		if (!temp)
			return (NULL);
		ft_free(*s, s, fd);
		s[fd] = ft_strjoin(temp, buffer);
		if (!s[fd])
			return (NULL);
		ft_free(temp, s, 0);
	}
	line = return_eof_or_eol(s, fd, buffer, 1);
	if (line)
		ft_free(buffer, s, 0);
	return (line);
}

static	char	*gnl_2(char **s, int fd, char *buffer, char *line)
{
	int	input;

	input = read(fd, buffer, BUFFER_SIZE);
	while (input > 0)
	{
		buffer[input] = '\0';
		line = read_buffer(s, fd, buffer, line);
		if (line)
			return (line);
		input = read(fd, buffer, BUFFER_SIZE);
	}
	if (!input && s[fd] && s[fd][0])
		return (return_eof_or_eol(s, fd, buffer, 0));
	ft_free(buffer, s, 0);
	ft_free(*s, s, fd);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*s[FOPEN_MAX];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = return_eof_or_eol(s, fd, buffer, 1);
	if (line)
	{
		ft_free(buffer, s, 0);
		return (line);
	}
	return (gnl_2(s, fd, buffer, line));
}
