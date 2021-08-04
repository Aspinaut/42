/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/04 20:45:12 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_free(char *s)
{
  if (s)
    free(s);
  s = NULL;
}

// static char *return_eol(char **s, int fd)
// {
//   char *temp;
  
//   temp = ft_strdup(s[fd]);
//   // ft_free(s[fd]);
//   return (temp);
// }

static char *check_static_eol(char **s, int fd)
{
  char *line;
  char *temp;
  
  line = NULL;
  temp = NULL;
  if (s[fd] && ft_strchr_pos(s[fd], '\n') >= 0)
  {
    line = ft_substr(s[fd], 0, ft_strchr_pos(s[fd], '\n') + 1);
    temp = ft_substr(s[fd], ft_strchr_pos(s[fd], '\n') + 1, ft_strlen(s[fd]) + 1);
    ft_free(s[fd]);
    s[fd] = ft_strdup(temp);
    ft_free(temp);
  }
  return (line);
}

static char *read_buffer(char **s, int fd, char *buffer, char *line)
{
  char *temp;

  temp = NULL;
  if (!s[fd])
  {
    s[fd] = ft_strdup(buffer);
  }
  else
  {
    temp = ft_strdup(s[fd]);
    ft_free(s[fd]);
    s[fd] = ft_strjoin(temp, buffer);
    ft_free(temp);
  }
  line = check_static_eol(s, fd);
  if (line)
    return (line);
  return (NULL);
}

char *get_next_line(int fd)
{
  char *buffer; 
  static char *s[OPEN_MAX];
  char *line;

  line = NULL;
  if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
    return (NULL);
  line = check_static_eol(s, fd);
  if (line)
    return (line);
  buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!buffer)
    return (NULL);
  while(read(fd, buffer, BUFFER_SIZE))
  {
    buffer[BUFFER_SIZE] = '\0';
    line = read_buffer(s, fd, buffer, line);
    if (line)
      return (line);
    // if (read(fd, buffer, BUFFER_SIZE) == 0)
    //   break ;
  }
  ft_free(buffer);
  if (read(fd, buffer, BUFFER_SIZE) == 0 && !s[fd])
    return (ft_strdup(""));
  return (ft_strdup(s[fd]));
  // return (NULL);
}

// int main(int ac, char **ag)
// {
//     char *s;
//     int fd;

//     fd = open(ag[1], O_RDONLY);
//     s = get_next_line(fd);
//     while (s)
//     {
//       printf("|%s", s);
//       ft_free(s);
//       s = get_next_line(fd);
//     }
//     printf("|%s", s);
//     ft_free(s);
//     close(fd);
//     // system("leaks gnl");
//     return (0);
// }
