/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:42 by vmasse            #+#    #+#             */
/*   Updated: 2022/01/03 14:54:38 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long int	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < time)
		usleep(50);
	return (1);
}

void  print_status(t_phi *philos, char *status)
{
  if (!philos->params->died)
  {
    pthread_mutex_lock(&philos->params->print);
    printf("%ldms %d %s\n", time_now() - philos->params->start_time, philos->id, status);
    pthread_mutex_unlock(&philos->params->print);
  }
}

void  ft_sleep_think(t_phi *philo)
{
  print_status(philo, SLEEP);
  ft_usleep(philo->params->to_sleep);
  print_status(philo, THINK);
}

void  ft_eat(t_phi *philo)
{
  pthread_mutex_lock(philo->l_fork);
  print_status(philo, FORK);
  pthread_mutex_lock(philo->r_fork);
  print_status(philo, FORK);
  print_status(philo, EAT);
  philo->start_eating = time_now();
  ft_usleep(philo->params->to_eat);
  philo->meals++;
  if (philo->params->eat_max && philo->meals >= philo->params->eat_max)
    philo->params->start = 0;
  pthread_mutex_unlock(philo->l_fork);
  pthread_mutex_unlock(philo->r_fork);
}

void *routine(void *job)
{
  t_phi *philo;

  philo = job;
  while (!philo->params->start);
  if (philo->id % 2 == 0)
    usleep(philo->params->to_eat * 0.5);
  while (!philo->params->died)
  {
    if (philo->params->eat_max && philo->meals >= philo->params->eat_max)
      break ;
    ft_eat(philo);
    ft_sleep_think(philo);
  }
  return (NULL);
}

void free_philos(t_phi *philos, t_params *params)
{
  int i;

  i = -1;
  while (++i < philos->params->philos)
  {
    pthread_join(philos[i].thread, NULL);
    pthread_mutex_destroy(philos[i].l_fork);
  }
  pthread_mutex_destroy(&params->print);
  free(philos);
}

t_phi *init_philos(t_phi *philos, t_params *params)
{
  long int  starting_time;
  int       i;

  i = -1;
  philos = malloc(sizeof(t_phi) * params->philos);
  if (!philos)
    return (NULL);
  while (++i < params->philos)
  {
    philos[i].params = params;
    philos[i].id = i + 1;
    philos[i].meals = 0;
    pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
    philos[i].l_fork = malloc(sizeof(pthread_mutex_t));
    if (!philos[i].l_fork)
      return (NULL);
    pthread_mutex_init(philos[i].l_fork, NULL);
  }
  starting_time = time_now();
  i = -1;
  while (++i < params->philos)
  {
    philos[i].r_fork = philos[(i + 1) % params->philos].l_fork;
    philos[i].start_eating = starting_time;
  }
  params->start = 1;
  params->start_time = starting_time;
  return (philos);
}

int check_args(t_params *params)
{
  if (params->philos < 1)
    return (ft_exit(0, "Error\nWrong number of philos\n"));
  if (params->to_die < 1 || params->to_die > INT_MAX)
    return (ft_exit(0, "Error\nWrong time to die\n"));
  if (params->to_eat < 1 || params->to_eat > INT_MAX)
    return (ft_exit(0, "Error\nWrong time to eat\n"));
  if (params->to_sleep < 1 || params->to_sleep > INT_MAX)
    return (ft_exit(0, "Error\nWrong time to sleep\n"));
  if (params->eat_max < 0 || params->eat_max > INT_MAX)
    return (ft_exit(0, "Error\nWrong eat max\n"));
  return (1);
}

int  init_params(t_params *params, char **argv)
{
  params->philos = ft_atoi(argv[1]);
  params->to_die = ft_atoi(argv[2]);
  params->to_eat = ft_atoi(argv[3]);
  params->to_sleep = ft_atoi(argv[4]);
  params->start = 0;
  params->died = 0;
  pthread_mutex_init(&params->print, NULL);
  if (argv[5])
    params->eat_max = ft_atoi(argv[5]);
  else
    params->eat_max = 0;
  return (check_args(params));
}

void  check_death(t_phi *philos, t_params *params)
{
  int i;

  while (!philos->params->start);
  while (!params->died)
  {
    i = -1;
    while (++i < philos->params->philos)
    {
      if ((time_now() - philos[i].start_eating) > params->to_die)
      {
        print_status(philos, DIE);
        params->died = 1;
        pthread_mutex_unlock(philos[i].l_fork);
        pthread_mutex_unlock(philos[i].r_fork);
        break ;
      }
    }
  }
}

int main(int argc, char **argv)
{
  t_params      params;
  t_phi         *philos;

  philos = NULL;
  if (argc != 5 && argc != 6)
    return (ft_exit(1, "Error\nWrong nb of arguments\n"));
  if (!init_params(&params, argv))
    return (ft_exit(1, "Failed to init params\n"));
  philos = init_philos(philos, &params);
  if (!philos)
    return (ft_exit(1, "Error\nFailed to init philos\n"));
  check_death(philos, &params);
  free_philos(philos, &params);
  return (0);
}
