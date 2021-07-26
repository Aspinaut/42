/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/26 16:47:24 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *result;
    // pourquoi buffer size + 1 ?
    char *buffer[BUFFER_SIZE + 1];

    int i = 0;
    while(read(fd, buffer, BUFFER_SIZE))
    {
        write(1, *buffer , 1);
        i++;
    }
    return (result);
}

int main()
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    get_next_line(fd);
    // line = "a";
    // while(line)
    // {
    //     line = get_next_line(fd);
    //     printf("%d\n", fd);
    // }
    return 0;
}