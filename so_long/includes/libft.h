/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:24:37 by vmasse            #+#    #+#             */
/*   Updated: 2021/11/04 18:23:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define MAX_LONG	9223372036854775807

int		ft_putstr_fd(char const *s, int fd);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strdup(char *src);
int		ft_strchr(const char *s, int c);
int		ft_strlen(const char *str);

#endif
