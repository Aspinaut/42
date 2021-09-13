/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:27:39 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 13:27:13 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char *find_env_paths(char **envp)
{
  char *env_paths;

  if (!envp)
    return (NULL);
  while (*envp)
  {
    if (strncmp(*envp, "PATH=", 5))
    {
      env_paths = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
      if (!env_paths)
        return (NULL);
      break ;
    }
    envp++;
  }
  return (env_paths);
}

void init_t_child(t_child *child, int pfd[2])
{
    child->id = 0;
    child->env_paths = NULL;
    child->fd = 0;
    child->cmd = NULL;
    child->file = NULL;
    child->pfd[0] = pfd[0];
    child->pfd[1] = pfd[1];
}

// void ft_free(char *s)
// {
//   if (s)
//     free(s)
//   s = NULL;
// }
