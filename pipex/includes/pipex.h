/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:18:58 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/15 11:25:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_child
{
	int		id;
	int		cmd_pos;
	pid_t	pid;
	int		fd;
	int		pfd[2];
	char	**cmd_args;
	char	*cmd_path;
	char	**env_paths;
}		t_child;

void	pipex(int fd1, int fd2, char **envp, char **argv);
char	*find_env_paths(char **envp);
char	**get_env_paths(char **envp);
void	process_child_cmd(t_child child, char **envp, char **argv, char **e);
void	free_child(t_child *child);
void	child_process(t_child *child, char **envp, char **argv, char **e);
void	init_child(t_child *child, int pfd[2], int fd, char **env_paths);
void	ft_free(char **s);
int		arr_len(char **s);
void	print_cmd_not_found(char *cmd_args);

#endif
