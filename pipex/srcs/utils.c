/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:27:39 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 21:41:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void ft_free(char **s)
{
  while (s && *s)
  {
    free(*s);
    s++;
  }
  if (s)
    free(s);
  s = NULL;
}

char *find_env_paths(char **envp)
{
  char *env_paths_line;

  if (!envp)
    return (NULL);
  while (*envp)
  {
    if (!ft_strncmp(*envp, "PATH=", 5))
    {
      env_paths_line = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
      if (!env_paths_line)
        return (NULL);
      break ;
    }
    envp++;
  }
  return (env_paths_line);
}

char **get_env_paths(char **envp)
{
  char **env_paths;
  char *env_paths_line;

  env_paths_line = find_env_paths(envp);
  if (!env_paths_line)
    return (NULL);
  env_paths = ft_split(env_paths_line, ':');
  free(env_paths_line);
  if (!env_paths)
    return (NULL);
  return (env_paths);
}
