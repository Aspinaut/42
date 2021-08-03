/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:18:43 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/03 18:25:22 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str && str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*string;
	int		src_size;
	int		i;

	i = 0;
	src_size = ft_strlen(src);
	string = malloc(sizeof(char) * (src_size + 1));
	if (!string)
		return (NULL);
	while (i < src_size)
	{
		string[i] = src[i];
		i++;
	}
	string[src_size] = '\0';
	return (string);
}

int	ft_strchr_pos(const char *s, char c)
{
	int pos;

	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (pos);
		pos++;
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sample;
	size_t	i;
	int		len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < (int)start)
		len = 0;
	else if (len_s < ((int)start + (int)len))
		len = len_s - start;
	sample = (char *)malloc((len + 1) * sizeof(char));
	if (!(sample))
		return (NULL);
	i = 0;
	while (i <= len)
	{
		sample[i] = s[start];
		start++;
		i++;
	}
	sample[i] = '\0';
	return (sample);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) + \
	ft_strlen((char *)s2) + 1));
	if (!(s3))
		return (NULL);
	i = -1;
	while (s1[++i])
		s3[i] = s1[i];
	s3[i] = '\0';
	i = -1;
	len = ft_strlen(s3);
	while (s2[++i])
		s3[len + i] = s2[i];
	s3[len + i] = '\0';
	return (s3);
}

// char	*ft_strndup(char *src, size_t n)
// {
// 	char	*string;
// 	size_t		i;

// 	i = 0;
// 	string = malloc(sizeof(char) * (n + 1));
// 	if (!(string))
// 		return (NULL);
// 	while (i < n)
// 	{
// 		string[i] = src[i];
// 		i++;
// 	}
// 	string[n] = '\0';
// 	return (string);
// }

char	*ft_strndup(char *src, size_t n)
{
	char	*s;
	size_t		i;
	int len_src;

	i = 0;
	len_src = ft_strlen(src);
	s = malloc(sizeof(char) * (n + 1));
	if (!s)
		return (NULL);
	while (src && i < n)
	{
		*s = *src;
		s++;
		src++;
		i++;
	}
	*s = '\0';
	return (s - len_src);
}