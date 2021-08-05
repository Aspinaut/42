/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/05 19:49:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_free(char *s)
{
  if (s)
    free(s);
  s = NULL;
}

static void free_static(char **s, int fd)
{
  if (s)
  {
    free(s[fd]);
    s[fd] = NULL;
  }
}

static char *return_eof(char **s, int fd, char *buffer)
{
  char *temp;

  temp = ft_strdup(s[fd]);
  ft_free(buffer);
  free_static(s, fd);
  return (temp);
}

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
    free_static(s, fd);
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
    s[fd] = ft_strdup(buffer);
  // else if (!s[fd] && !buffer[0])
  //   s[fd] = ft_strdup("");
  else
  {
    temp = ft_strdup(s[fd]);
    free_static(s, fd);
    s[fd] = ft_strjoin(temp, buffer);
    ft_free(temp);
  }
  line = check_static_eol(s, fd);
  if (line)
    ft_free(buffer);
  return (line);
}

char *get_next_line(int fd)
{
  char *buffer;
  static char *s[FOPEN_MAX];
  char *line;
  int input;

  line = NULL;
  if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
    return (NULL);
  buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!buffer)
    return (NULL);
  line = check_static_eol(s, fd);
  if (line)
  {
    ft_free(buffer);
    return (line);
  }
  input = read(fd, buffer, BUFFER_SIZE);
  while(input > 0)
  {
    buffer[input] = '\0';
    line = read_buffer(s, fd, buffer, line);
    if (line)
      return (line);
    input = read(fd, buffer, BUFFER_SIZE);
  }
  if (!input && s[fd] && s[fd][0])
    return (return_eof(s, fd, buffer));
  ft_free(buffer);
  free_static(s, fd);
  return (NULL);
}

// int main(int ac, char **ag)
// {
//   char *s;
//   int fd;

//   fd = open(ag[1], O_RDONLY);
//   s = get_next_line(fd);
//   while (s && s[0])
//   {
//     printf("|%s", s);
//     ft_free(s);
//     s = get_next_line(fd);
//   }
//   printf("|%s", s);
//   ft_free(s);
//   close(fd);
//   system("leaks gnl");
//   return (0);
// }
