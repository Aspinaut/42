/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:27:39 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/15 11:19:34 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	print_cmd_not_found(char *cmd_args)
{
	write(2, "bash: ", 6);
	write(2, cmd_args, ft_strlen(cmd_args));
	write(2, " : command not found\n", 21);
}

int	arr_len(char **s)
{
	int	len;

	len = 0;
	if (!s)
		return (len);
	while (s && *s)
	{
		s++;
		len++;
	}
	return (len);
}

void	ft_free(char **s)
{
	int	i;

	i = -1;
	while (s && s[++i])
		free(s[i]);
	if (s)
		free(s);
	s = NULL;
}

char	*find_env_paths(char **envp)
{
	char	*env_paths_line;

	if (!envp)
		return (NULL);
	while (envp && *envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
		{
			env_paths_line = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
			if (!env_paths_line)
				return (NULL);
			return (env_paths_line);
		}
		envp++;
	}
	return (NULL);
}

char	**get_env_paths(char **envp)
{
	char	**env_paths;
	char	*env_paths_line;

	env_paths_line = find_env_paths(envp);
	if (!env_paths_line)
		return (NULL);
	env_paths = ft_split(env_paths_line, ':');
	free(env_paths_line);
	if (!env_paths)
		return (NULL);
	return (env_paths);
}
