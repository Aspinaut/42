/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:18:58 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/14 10:40:00 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>

// check la bonne pour error - strerror
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
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
int		ft_putstr_fd(char const *s, int fd);
char	*find_env_paths(char **envp);
char	**get_env_paths(char **envp);
void	process_child_cmd(t_child child, char **envp, char **argv);
void	free_child(t_child *child);
int		child_process(t_child *child, char **envp, char **argv);
void	init_child(t_child *child, int pfd[2], int fd, char **env_paths);
void	ft_free(char **s);

#endif
