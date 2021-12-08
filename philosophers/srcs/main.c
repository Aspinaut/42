/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:42 by vmasse            #+#    #+#             */
/*   Updated: 2021/12/08 17:22:09 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void *p1()
// {
//   int i = 0;
//   char s[1500] = "Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !";

//   while (s[i])
//   {
//     // usleep(100);
//     fprintf(stderr, "%c\n", s[i]);
//     i++;
//   }
//   return (NULL);
// }

// void *p2()
// {
//   int i = 0;
//   char s[1500] = "Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !";

//   while (s[i])
//   {
//     // usleep(100);
//     fprintf(stderr, "%c\n", s[i]);
//     i++;
//   }
//   return (NULL);
// }

void init_philos(t_phi *philo, char **argv)
{
  int     i;
  t_phi   prev;
  int     stop;

  stop = ft_atoi(argv[1]);
  i = -1;
  while (++i < stop)
  {
    philo->to_die = ft_atoi(argv[2]);
    philo->to_eat = ft_atoi(argv[3]);
    philo->to_sleep = ft_atoi(argv[4]);
    philo->id = i;
    if (argv[5])
      philo->eat_max = ft_atoi(argv[5]);
    if (i == 0)
      philo->prev = NULL;
    else 
    {
      philo->prev = &prev;
      philo->prev->next = philo;
    }
    prev = *philo;
    philo->next = NULL;
  }
}

int main(int argc, char **argv)
{
  t_phi     philo;

  if (argc != 5 && argc != 6)
    ft_exit("Error\nWrong nb of arguments\n");
  if (!check_args(argv))
    ft_exit("Error\nSomething wrong with arguments\n");
  init_philos(&philo, argv);
  while (philo)
  {
    printf("%d\n", philo);
    philo = philo.next;
  }
  // pthread_create(&t1, NULL, p1, NULL);
  // pthread_create(&t2, NULL, p2, NULL);
  // pthread_join(t2, NULL);
  // pthread_join(t1, NULL);
  return (0);
}
