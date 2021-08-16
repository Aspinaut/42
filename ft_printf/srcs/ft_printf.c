/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:05:13 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/16 17:07:42 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
  - checker si on trouve des %
    si oui :
      - compter le nb de % et comparer avec les va_args
      - put_str de tout ce qui précède
      -
    sinon :
      - putstr

    while s != '%'
      if (*(s + 1) == '%')
        putchar %

*/

int ft_printf(const char *s, ...)
{
  va_list args;
  va_start(args, s);

  ft_putstr(s);

  va_end(args);
  return (0);
}

int main()
{
  char *s = "salut";
  int i = 0;
  ft_printf("FT_PRINTF : \n", s, i);
  // ft_printf("FT_PRINTF : salut %%\n");
  printf("%d", printf("PRINTF : salut %d\n"));
  return (0);
}
