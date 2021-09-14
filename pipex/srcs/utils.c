/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 09:27:39 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/15 00:48:16 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void print_cmd_not_found(char *cmd_args)
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

int check_cmd(char *arg, char **envp)
{
	int i;
	char **env_paths;
	char *tmp;
	char *cmd_path;

	if (!arg[0])
	{
		print_cmd_not_found(arg);
		exit(EXIT_FAILURE);
	}
	i = -1;
	env_paths = get_env_paths(envp);
	while (env_paths[++i])
	{
		tmp = ft_strjoin(env_paths[i], "/");
		if (!tmp)
			return (0);
		cmd_path = ft_strjoin(tmp, arg);
		if (!cmd_path)
			return (0);
		free(tmp);
		if (access(cmd_path, F_OK | X_OK) != -1)
		{
			free(cmd_path);
			ft_free(env_paths);
			return (1);
		}
		free(cmd_path);
	}
	print_cmd_not_found(arg);
	ft_free(env_paths);
	return (0);
}
