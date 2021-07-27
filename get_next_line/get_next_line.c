/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/27 10:51:53 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    static char **before_new_line;

    *before_new_line = (char **)malloc(sizeof(char) * (4096 + 1));
    while(read(fd, buffer, BUFFER_SIZE))
    {
        if(ft_strrchr(buffer, '\n'))
        {
            // printf("BUFFER IF char: %c\n", *buffer);
            // printf("BUFFER IF str: %s\n", buffer);
            
            // si on trouve des chars apres le \n dans buffer, on les met dans static
            
            // ensuite on print buffer - tout ce qui se trouve apres le \n
            printf("%s\n", ft_substr(buffer, 0, 3));
            // write(1, ft_substr(buffer, 0, ), 1);
            // et on avance au prochain tableau dans la static
            before_new_line++;
        }
        else
        {
            // printf("BUFFER ELSE char: %c\n", *buffer);
            // printf("BUFFER ELSE str: %s\n", buffer);
            
            // on met buffer dans la static
            *before_new_line = buffer;
            printf("STATIC : %s\n", before_new_line);
        }
        
    }
    return (before_new_line);
}

int main()
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    get_next_line(fd);
    return 0;
}