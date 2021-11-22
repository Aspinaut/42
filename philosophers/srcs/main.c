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

int main()
{
  pthread_t t1;
  pthread_t t2;

  pthread_create(&t1, NULL, p1, NULL);
  pthread_create(&t2, NULL, p2, NULL);
  pthread_join(t2, NULL);
  pthread_join(t1, NULL);
  return (0);
}
