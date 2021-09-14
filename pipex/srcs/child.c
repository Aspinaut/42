/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:49:26 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/14 19:33:57 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_child(t_child *child)
{
	ft_free(child->cmd_args);
	ft_free(child->env_paths);
}

void	init_child(t_child *child, int pfd[2], int fd, char **env_paths)
{
	int	i;

	if (fd == 3)
	{
		child->id = 1;
		child->cmd_pos = 2;
	}
	else if (fd == 4)
	{
		child->id = 2;
		child->cmd_pos = 3;
	}
	child->pid = 0;
	child->fd = fd;
	child->pfd[0] = pfd[0];
	child->pfd[1] = pfd[1];
	child->cmd_args = NULL;
	child->cmd_path = NULL;
	i = arr_len(env_paths);
	child->env_paths = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env_paths[++i])
		child->env_paths[i] = ft_strdup(env_paths[i]);
	child->env_paths[i] = 0;
}

void	process_child_cmd(t_child child, char **envp, char **argv, char **e)
{
	int		i;
	char	*tmp;

	child.cmd_args = ft_split(argv[child.cmd_pos], ' ');
	i = -1;
	while (child.env_paths[++i])
	{
		tmp = ft_strjoin(child.env_paths[i], "/");
		if (!tmp)
			return ;
		child.cmd_path = ft_strjoin(tmp, child.cmd_args[0]);
		if (!child.cmd_path)
			return ;
		free(tmp);
		if (access(child.cmd_path, F_OK | X_OK) != -1)
			execve(child.cmd_path, child.cmd_args, envp);
		free(child.cmd_path);
	}
	write(2, "bash: ", 6);
	write(2, child.cmd_args[0], ft_strlen(child.cmd_args[0]));
	write(2, " : command not found\n", 21);
	free_child(&child);
	ft_free(e);
	exit(EXIT_FAILURE);
}

void	child_process(t_child *child, char **envp, char **argv, char **e)
{
	if (child->id == 1)
	{
		dup2(child->fd, STDIN_FILENO);
		dup2(child->pfd[1], STDOUT_FILENO);
		close(child->pfd[0]);
	}
	else if (child->id == 2)
	{
		dup2(child->pfd[0], STDIN_FILENO);
		dup2(child->fd, STDOUT_FILENO);
		close(child->pfd[1]);
	}
	close(child->fd);
	process_child_cmd(*child, envp, argv, e);
}
