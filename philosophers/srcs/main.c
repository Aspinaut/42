/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:42 by vmasse            #+#    #+#             */
/*   Updated: 2021/12/29 10:48:02 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *p1()
{
  int i = 0;
  char s[1500] = "Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !Bonjour !";

  while (s[i])
  {
    // usleep(100);
    // fprintf(stderr, "%c\n", s[i]);
    i++;
  }
  return (NULL);
}

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
//   return 

void free_philos(t_phi *philos)
{
  // int i;

  // i = -1;
  // while (++i < philos->params->philos)
  // {
  //   free(philos[i]);
  // }
  free(philos);
}

t_phi *init_philos(t_phi *philos, t_params params)
{
  int     i;

  i = -1;
  philos = malloc(sizeof(t_phi) * params.philos);
  if (!philos)
    return (NULL);
  while (++i < params.philos)
  {
    philos[i].id = i;
    pthread_create(&philos[i].thread, NULL, p1, &philos[i]);
    philos[i].params = &params;
  }
  return (philos);
}

void  init_params(t_params *params, char **argv)
{
  params->philos = ft_atoi(argv[1]);
  params->to_die = ft_atoi(argv[2]);
  params->to_eat = ft_atoi(argv[3]);
  params->to_sleep = ft_atoi(argv[4]);
  params->start = 0;
  params->died = 0;
  if (argv[5])
    params->eat_max = ft_atoi(argv[5]); 
}

int main(int argc, char **argv)
{
  t_params      params;
  t_phi         *philos;

  philos = NULL;
  if (argc != 5 && argc != 6)
    ft_exit("Error\nWrong nb of arguments\n");
  if (!check_args(argv))
    ft_exit("Error\nSomething wrong with arguments\n");
  init_params(&params, argv);
  philos = init_philos(philos, params);
  if (!philos)
    ft_exit("Error\nFailed to init philos\n");

  int i = 0;
  // printf("%d\n", phi1los[i].id);

  while (i < params.philos)
  {
    printf("%d\n", philos[i].id);
    i++;
  }
  // pthread_create(&t1, NULL, p1, NULL);
  // pthread_create(&t2, NULL, p2, NULL);
  // pthread_join(t2, NULL);
  // pthread_join(t1, NULL);
  
  free_philos(philos);
  return (0);
}
