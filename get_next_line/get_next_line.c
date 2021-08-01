/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/01 16:48:10 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    static char *before_new_line;
    char *temp;

    if (!before_new_line)
    {
      before_new_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
      if (!before_new_line)
        return (NULL);
    }
    temp = NULL;
    while(read(fd, buffer, BUFFER_SIZE))
    {
      if(ft_strrchr(buffer, '\n'))
      {
        if (buffer[ft_strlen(buffer) - 1] == '\n')
        {
          temp = ft_strjoin(before_new_line, buffer);
          free(before_new_line);
          return (temp);
        }
        else
        {
          temp = ft_strjoin(before_new_line, ft_substr(buffer, 0, ft_strchrpos(buffer, '\n') + 1));
          free(before_new_line);
          // printf("TEMP : %s\n", temp);
          before_new_line = ft_substr(buffer, ft_strchrpos(buffer, '\n') + 1, BUFFER_SIZE - 1);
          // printf("SUBSTR STATIC: %s\n", before_new_line);
          return (temp);
        }
      }
      else
      {
        before_new_line = ft_strjoin(before_new_line, buffer);
        // printf("ELSE : %s\n", before_new_line);
        return (get_next_line(fd));
      }
    }
    return (before_new_line);
}

int main()
{
    int fd;
    char *line;
    int i;

    fd = open("file.txt", O_RDONLY);
    i = 0;
    while (i < 3)
    {
      printf("GNL (%d) : %s\n", i, get_next_line(fd));
      i++;
    }
    return (0);
}
