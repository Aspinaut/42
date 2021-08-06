/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/06 14:18:25 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_free(char *s, char **sta, int fd)
{
  if (sta && fd)
  {
    free(sta[fd]);
    sta[fd] = NULL;
    return ;
  }
  if (s)
    free(s);
  s = NULL;
}

// static char *return_eof(char **s, int fd, char *buffer)
// {
//   char *temp;

//   temp = ft_strndup(s[fd], ft_strlen(s[fd]));
//   ft_free(buffer, s, 0);
//   ft_free(*s, s, fd);
//   return (temp);
// }

// static char *check_static_eol(char **s, int fd)
// {
//   char *line;
//   char *temp;

//   line = NULL;
//   temp = NULL;
//   if (s[fd] && ft_strchr_pos(s[fd], '\n') >= 0)
//   {
//     // line = ft_strndup(s[fd], ft_strchr_pos(s[fd], '\n') + 1);
//     // temp = ft_strndup(s[fd] + (ft_strchr_pos(s[fd], '\n') + 1), ft_strlen(s[fd]) - (ft_strchr_pos(s[fd], '\n') + 1));
//     line = ft_substr(s[fd], 0, ft_strchr_pos(s[fd], '\n') + 1);
//     temp = ft_substr(s[fd], ft_strchr_pos(s[fd], '\n') + 1, ft_strlen(s[fd]) + 1);
//     ft_free(*s, s, fd);
//     s[fd] = ft_strndup(temp, ft_strlen(temp));
//     ft_free(temp, s, 0);
//   }
//   return (line);
// }

static char *return_eof_or_eol(char **s, int fd, char *buffer, int check_static)
{
  char *line;
  char *temp;

  line = NULL;
  temp = NULL;
  if (check_static)
  {
    if (s[fd] && ft_strchr_pos(s[fd], '\n') >= 0)
    {
      line = ft_substr(s[fd], 0, ft_strchr_pos(s[fd], '\n') + 1);
      temp = ft_substr(s[fd], ft_strchr_pos(s[fd], '\n') + 1, ft_strlen(s[fd]) + 1);
      ft_free(*s, s, fd);
      s[fd] = ft_strndup(temp, ft_strlen(temp));
      ft_free(temp, s, 0);
    }
  }
  else 
  {
    temp = ft_strndup(s[fd], ft_strlen(s[fd]));
    ft_free(buffer, s, 0);
    ft_free(*s, s, fd);
    return (temp);
  }
  return (line);
}

static char *read_buffer(char **s, int fd, char *buffer, char *line)
{
  char *temp;

  temp = NULL;
  if (!s[fd])
    s[fd] = ft_strndup(buffer, ft_strlen(buffer));
  else
  {
    temp = ft_strndup(s[fd], ft_strlen(s[fd]));
    ft_free(*s, s, fd);
    s[fd] = ft_strjoin(temp, buffer);
    ft_free(temp, s, 0);
  }
  line = return_eof_or_eol(s, fd, buffer, 1);
  if (line)
    ft_free(buffer, s, 0);
  return (line);
}
static char *gnl_2(int input, char **s, int fd, char *buffer, char *line)
{
  while(input > 0)
  {
    buffer[input] = '\0';
    line = read_buffer(s, fd, buffer, line);
    if (line)
      return (line);
    input = read(fd, buffer, BUFFER_SIZE);
  }
  if (!input && s[fd] && s[fd][0])
    return (return_eof_or_eol(s, fd, buffer, 0));
  ft_free(buffer, s, 0);
  ft_free(*s, s, fd);
  return (NULL);
}

char *get_next_line(int fd)
{
  char *buffer;
  static char *s[OPEN_MAX];
  char *line;
  int input;

  line = NULL;
  if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX)
    return (NULL);
  buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
  if (!buffer)
    return (NULL);
  line = return_eof_or_eol(s, fd, buffer, 1);
  if (line)
  {
    ft_free(buffer, s, 0);
    return (line);
  }
  input = read(fd, buffer, BUFFER_SIZE);
  return (gnl_2(input, s, fd, buffer, line));
}