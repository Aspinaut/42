/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:05:03 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/22 17:10:21 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  int find_total_digit(long n) {
  int total_digit;

  if (n == 0) {
    total_digit = 1;
  } else {
    total_digit = 0;
  }
  if (n < 0) {
    total_digit++;
  }
  while (n != 0) {
    total_digit++;
    n /= 10;
  }
  return total_digit;
}

char *ft_itoa(int n) {
  char *result;
  long temp_n;
  int total_digit;

  temp_n = n;
  total_digit = find_total_digit(temp_n);
  if(!(result = (char *)malloc(sizeof(char) * (total_digit + 1)))) {
    return NULL;
  }
  result[total_digit] = '\0';
  if (temp_n == 0) {
    result[0] = '0';
  }
  if (temp_n < 0) {
    temp_n = temp_n * - 1;
    result[0] = '-';
  }
  while (temp_n != 0) {
    result[total_digit - 1] = (temp_n % 10) + '0';
    total_digit--;
    temp_n /= 10;
  }
  return result;
}
