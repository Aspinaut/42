#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

# define	MAX_LONG	9223372036854775807
# define    FORK        "has taken a fork"
# define    DIE         "died"
# define    SLEEP       "is sleeping"
# define    THINK       "is thinking"
# define    EAT         "is eating"

typedef struct s_params
{
    int             to_die;
    int             to_eat;
    int             to_sleep;
    int             philos;
    int             eat_max;
    int             start;
    long int        start_time;
    int             died;
    pthread_mutex_t print;
}               t_params;

typedef struct s_phi
{
    int             id;
    long int        start_eating;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;
    pthread_t		thread;
    t_params        *params;
}                   t_phi;

/* UTILS */

int     ft_strlen(const char *str);
void    ft_exit(char *msg);
int	    ft_atoi(const char *str);

void     init_params(t_params *params, char **argv);

#endif
