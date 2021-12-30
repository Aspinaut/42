/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:42 by vmasse            #+#    #+#             */
/*   Updated: 2021/12/30 15:14:40 by vmasse           ###   ########.fr       */
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
		usleep(150);
	return (1);
}

void  ft_eat(t_phi *philos)
{
  pthread_mutex_lock(philos->l_fork);
  pthread_mutex_lock(&philos->params->print);
  printf("Philo %d has taken a fork\n", philos->id);
  pthread_mutex_unlock(&philos->params->print);
  pthread_mutex_lock(philos->r_fork);
  pthread_mutex_lock(&philos->params->print);
  printf("Philo %d has taken a fork\n", philos->id);
  pthread_mutex_unlock(&philos->params->print);
  pthread_mutex_lock(&philos->params->print);
  printf("Philo %d is eating\n", philos->id);
  pthread_mutex_unlock(&philos->params->print);
  pthread_mutex_unlock(philos->r_fork);
  pthread_mutex_unlock(philos->l_fork);

}

void *routine(void *job)
{
  t_phi *philos;

  philos = job;
  while (!philos->params->start);
  if (philos->id % 2 == 1)
    usleep(3);
  while (!philos->params->died)
  {
    // pthread_mutex_lock(&philos->params->print);
    // printf("Philo is alive\n");
    // pthread_mutex_unlock(&philos->params->print);
    ft_eat(philos);
  }
  return (NULL);
}

void free_philos(t_phi *philos, t_params *params)
{
  int i;

  i = -1;
  printf("here");
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
  int     i;

  i = -1;
  philos = malloc(sizeof(t_phi) * params->philos);
  if (!philos)
    return (NULL);
  while (++i < params->philos)
  {
    philos[i].params = params;
    philos[i].id = i + 1;
    pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
    philos[i].l_fork = malloc(sizeof(pthread_mutex_t));
    // philos[i].r_fork = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(philos[i].l_fork, NULL);
  }
  i = -1;
  while (++i < params->philos)
    philos[i].r_fork = philos[(i + 1) % params->philos].l_fork;
  params->start = 1;
  return (philos);
}

void check_args(t_params *params)
{
  if (params->philos < 1)
    ft_exit("Error\nWrong number of philos\n");
  if (params->to_die < 1 || params->to_die > INT_MAX)
    ft_exit("Error\nWrong time to die\n");
  if (params->to_eat < 1 || params->to_eat > INT_MAX)
    ft_exit("Error\nWrong time to eat\n");
  if (params->to_sleep < 1 || params->to_sleep > INT_MAX)
    ft_exit("Error\nWrong time to sleep\n");
  if (params->eat_max < 0 || params->eat_max > INT_MAX)
    ft_exit("Error\nWrong eat max\n");
}

void  init_params(t_params *params, char **argv)
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
  check_args(params);
}

void  check_death(t_phi *philos, t_params *params)
{
  int i;

  i = -1;
  while (philos->params->start);
  while (++i < philos->params->philos)
  {

  }
}

int main(int argc, char **argv)
{
  t_params      params;
  t_phi         *philos;

  philos = NULL;
  if (argc != 5 && argc != 6)
    ft_exit("Error\nWrong nb of arguments\n");
  init_params(&params, argv);
  philos = init_philos(philos, &params);
  if (!philos)
    ft_exit("Error\nFailed to init philos\n");
  check_death(philos, &params);
  free_philos(philos, &params);
  return (0);
}
