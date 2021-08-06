/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:46 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/06 08:58:48 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// attention bien faire le tri avant evaluation !

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char    *get_next_line(int fd);
int     ft_strlen(const char *str);
// char	*ft_strdup(char *src);
char	*ft_strndup(char *src, size_t n);
int     ft_strchr_pos(const char *s, char c);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);

#endif