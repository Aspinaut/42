/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/07/27 17:24:11 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    static char *before_new_line;
    char *temp;

    before_new_line = NULL;
    temp = NULL;
    while(read(fd, buffer, BUFFER_SIZE))
    {   
        printf("RCHR : %s\n", ft_strrchr(buffer, '\n'));
        if(ft_strrchr(buffer, '\n'))
        {
            before_new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
            if (!before_new_line)
                return (NULL);
            before_new_line = ft_substr(buffer, 1, BUFFER_SIZE - 1);
            printf("SUB : %s\n", ft_substr(buffer, 0, 3));
        }
        else
        {
            temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
            temp = ft_strjoin(before_new_line, buffer);
            printf("ELSE : %s\n", temp);
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