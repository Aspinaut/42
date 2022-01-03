/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:06:54 by vmasse            #+#    #+#             */
/*   Updated: 2022/01/03 15:14:38 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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