/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:58:50 by vmasse            #+#    #+#             */
/*   Updated: 2022/01/03 15:01:49 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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