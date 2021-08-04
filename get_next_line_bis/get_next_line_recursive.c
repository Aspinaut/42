/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_old.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 15:15:44 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/03 10:40:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strchrpos(const char *s, char c, int check_uniqueness)
{
	int i;

	i = 0;
	if (!check_uniqueness)
		while (s[i] && s[i] != c)
			i++;
	else
		while (*s)
			if (*s++ == c)
				i++;
	return (i);
}

static int  check_static_end_line(char *s)
{
  int has_end_line;

  has_end_line = 0;
  while (*s)
  {
    if (*s == '\n')
      has_end_line++;
    s++;
  }
  return (has_end_line);
}

char *get_next_line(int fd)
{
  char buffer[BUFFER_SIZE + 1]; 
  static char *s;
  char *line;

  if (BUFFER_SIZE <= 0 || fd < 0 || fd > FOPEN_MAX)
    return (NULL);
  if (!s)
  {
    s = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!s)
      return (NULL);
    s[BUFFER_SIZE] = '\0'; // + 1 ?
  }
  line = NULL;
  if (check_static_end_line(s))
  {
    line = ft_substr(s, 0, ft_strchrpos(s, '\n', 0) + 1);
    s = ft_substr(s, ft_strchrpos(s, '\n', 0) + 1, ft_strlen(s) + 1);
    return (line);
  }
  while(read(fd, buffer, BUFFER_SIZE))
  {
    
    if(ft_strrchr(buffer, '\n') && ft_strchrpos(buffer, '\n', 1) == 1)
    {
      if (buffer[BUFFER_SIZE] == '\n')
      {
        line = ft_strjoin(s, buffer);
        free(s);
        return (line);
      }
      else
      {
        line = ft_strjoin(s, ft_substr(buffer, 0, ft_strchrpos(buffer, '\n', 0) + 1));
        free(s);
        s = ft_substr(buffer, ft_strchrpos(buffer, '\n', 0) + 1, BUFFER_SIZE);
        return (line);
      }
    }
    else
    {
      s = ft_strjoin(s, buffer);
      return (get_next_line(fd));
    }
  }
  return (s);
}

int main(int ac, char **ag)
{
    char *s;
    int fd;

    fd = open(ag[1], O_RDONLY);
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
