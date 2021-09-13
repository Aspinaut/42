/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:27:39 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 16:40:18 by vmasse           ###   ########.fr       */
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
    if (!ft_strncmp(*envp, "PATH=", 5))
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