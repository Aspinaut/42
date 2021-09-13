/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:18:58 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/13 13:27:37 by vmasse           ###   ########.fr       */
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

typedef struct  s_child
{
  pid_t id;
  char *env_paths;
  int pfd[2];
  int fd;
  char *cmd;
  char *file;
} t_child;

char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void pipex(int fd1, int fd2, char **envp, char **argv);
char *find_env_paths(char **envp);
void init_t_child(t_child *child, int pfd[2]);
// void ft_free(char *s);

#endif
