/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:46 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/26 17:43:58 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// attention bien faire le tri avant evaluation !
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    *get_next_line(int fd);
char	*ft_strrchr(const char *s, int c);