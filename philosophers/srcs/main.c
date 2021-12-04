/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:42 by vmasse            #+#    #+#             */
/*   Updated: 2021/12/04 17:17:40 by vmasse           ###   ########.fr       */
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
    fprintf(stderr, "%c\n", s[i]);
    i++;
  }
  return (NULL);
}

void *p2()
{
  int i = 0;
  char s[1500] = "Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !Salut !";

  while (s[i])
  {
    // usleep(100);
    fprintf(stderr, "%c\n", s[i]);
    i++;
  }
  return (NULL);
}

int main(int argc, char **argv)
{
  pthread_t t1;
  pthread_t t2;
  // t_phi     philo;

  if (argc != 5 && argc != 6)
    ft_exit("Error\nWrong nb of arguments\n");
  if (!check_args(argv))
    ft_exit("Error\nSomething wrong with arguments\n");
  pthread_create(&t1, NULL, p1, NULL);
  pthread_create(&t2, NULL, p2, NULL);
  pthread_join(t2, NULL);
  pthread_join(t1, NULL);
  return (0);
}
