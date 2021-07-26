/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/26 18:19:19 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *result;
    // pourquoi buffer size + 1 ?
    char buffer[BUFFER_SIZE];
    // se renseigner sur la meilleure taille
    static char *before_line[4096];
    int i;
    // pourquoi avec un buffer size de 1 il insere random chars a la fin ??
    // while(read(fd, buffer, BUFFER_SIZE))
    // {
    //     write(1, &buffer[i], 1);
    //     printf("Printf : %c\n", buffer[i]);
    //     i++;
    // }
    // printf("LAST : %s\n", buffer);

    i = 0;
    while(read(fd, buffer, BUFFER_SIZE))
    {
        if(ft_strrchr(*buffer, '\n'))
        {
            printf("%c", *buffer);
        }
        else
        {
            // on met buffer dans la static
            *before_line = *buffer;
            *before_line += BUFFER_SIZE;
            buffer += BUFFER_SIZE;
        }
        
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