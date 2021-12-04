#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_phi
{
    int to_die;
    int to_eat;
    int to_sleep;
    int eat_max;
}               t_phi;

/* PARSING */

int     check_args(char **argv);

/* UTILS */

int     ft_strlen(const char *str);
void    ft_exit(char *msg);


#endif
