/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/03 18:49:50 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
  char *buffer; 
  static char *s[OPEN_MAX];
  char *line;
  char *temp;

  if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
    return (NULL);
  line = NULL;
  buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!buffer)
    return (NULL);
  while(read(fd, buffer, BUFFER_SIZE))
  {
    buffer[BUFFER_SIZE] = '\0';
    if (!s[fd])
    {
      s[fd] = ft_strdup(buffer);
    }
    else
    {
      s[fd] = ft_strjoin(s[fd], buffer);
    }
    if (ft_strchr_pos(s[fd], '\n') >= 0)
    {
      line = ft_substr(s[fd], 0, ft_strchr_pos(s[fd], '\n'));
      // printf("l %d\n", ft_strlen(line));
      temp = ft_substr(s[fd], ft_strchr_pos(s[fd], '\n') + 1, ft_strlen(s[fd]));
      printf("s %s\n", s[fd]);
      free(s[fd]);
      s[fd] = NULL;
      s[fd] = ft_strdup(temp);
      // printf("s %s\n", s);
      free(buffer);
      return (line);
    }
    free(buffer);
  }
  return (NULL);
}

int main(int ac, char **ag)
{
    char *s;
    int fd;

    fd = open(ag[1], O_RDONLY);

    s = "12345";
    // printf("%s\n", ft_substr(s, 0, ft_strlen(s)));
    // output = 123x

    // printf("%s\n", ft_strndup(s + 3, ft_strlen(s) - 3));
    // output = 45

    s = get_next_line(fd);
    while (s)
    {
      printf("|%s", s);
      free(s);
      s = get_next_line(fd);
    }
    close(fd);
    // system("leaks gnl");
    return (0);
}
