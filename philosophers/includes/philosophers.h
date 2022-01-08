/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:18:51 by vmasse            #+#    #+#             */
/*   Updated: 2022/01/08 12:40:25 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define MAX_LONG	9223372036854775807
# define FORK        "has taken a fork"
# define DIE         "died"
# define SLEEP       "is sleeping"
# define THINK       "is thinking"
# define EAT         "is eating"

typedef struct s_params
{
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				philos;
	int				eat_max;
	int				has_eat_max;
	int				start;
	int				died;
	long int		start_time;
	pthread_mutex_t	print;
}		t_params;

typedef struct s_phi
{
	int				id;
	int				meals;
	long int		start_eating;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		thread;
	t_params		*params;
}		t_phi;

/* ATOI */

int			ft_atoi(const char *str);

/* UTILS */

int			ft_strlen(const char *str);
int			ft_exit(int ret, char *err);
long int	time_now(void);
int			ft_usleep(long int time);
void		print_status(t_phi *philos, char *status);

/* ACTIONS */

void		ft_sleep_think(t_phi *philo);
void		ft_eat(t_phi *philo);
void		*routine(void *job);

/* PARAMS */

int			check_args(t_params *params);
int			init_params(t_params *params, char **argv);

/* PHILOS */

void		free_philos(t_phi *philos, t_params *params);
t_phi		*init_philos(t_phi *philos, t_params *params);

/* MAIN */

void		check_death(t_phi *philos, t_params *params, int last);

#endif
