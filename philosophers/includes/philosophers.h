#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# define	MAX_LONG	9223372036854775807

typedef struct s_phi
{
    int             to_die;
    int             to_eat;
    int             to_sleep;
    int             eat_max;
    int             id;
    pthread_mutex_t mutex;
    struct s_phi    *next;
    struct s_phi    *prev;
}                   t_phi;

/* PARSING */

int     check_args(char **argv);

/* UTILS */

int     ft_strlen(const char *str);
void    ft_exit(char *msg);
int	ft_atoi(const char *str);

#endif
