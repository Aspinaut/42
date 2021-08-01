/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/01 21:17:24 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE];
    static char *s;
    char *line;

    if (!s)
    {
      s = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
      if (!s)
        return (NULL);
    }
    line = NULL;
    while(read(fd, buffer, BUFFER_SIZE))
    {
      // printf("BUFFER : %s\n", buffer);
      if(ft_strrchr(buffer, '\n'))
      {
        if (buffer[ft_strlen(buffer) - 1] == '\n')
        {
          line = ft_strjoin(s, buffer);
          free(s);
          return (line);
        }
        else
        {
          line = ft_strjoin(s, ft_substr(buffer, 0, ft_strchrpos(buffer, '\n') + 1));
          free(s);
          // printf("line : %s\n", line);
          s = ft_substr(buffer, ft_strchrpos(buffer, '\n') + 1, BUFFER_SIZE - 1);
          // printf("SUBSTR STATIC: %s\n", s);
          return (line);
        }
      }
      else
      {
        s = ft_strjoin(s, buffer);
        // printf("ELSE : %s\n", s);
        return (get_next_line(fd));
      }
    }
    return (s);
}

int main()
{
    int fd;
    char *line;
    int i;

    fd = open("file.txt", O_RDONLY);
    i = 0;
    while (i < 4)
    {
      printf("GNL (%d) : %s\n", i, get_next_line(fd));
      i++;
    }
    return (0);
}
