/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 09:05:03 by vmasse            #+#    #+#             */
/*   Updated: 2021/06/22 11:16:57 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n) {
  char *result;
  int total_digit;
  int temp_n;

  temp_n = n;
  if (temp_n == 0) {
    total_digit = 1;
  } else {
    total_digit = 0;
  }
  if (temp_n < 0) {
    total_digit++;
  }
  while (temp_n != 0) {
    total_digit++;
    temp_n /= 10;
  }
  if(!(result = (char *)malloc(sizeof(char) * (total_digit + 1)))) {
    return NULL;
  }
  if (n == 0) {
    result[total_digit - 1] = '0';
  }
  if (n < 0) {
    n = n * -1;
    result[0] = '-';
  }
  while (n != 0) {
    result[total_digit - 1] = (n % 10) + '0';
    total_digit--;
    n /= 10;
  }

  return result;
}
// 
// int main() {
//   printf("%s", ft_itoa(-9846354));
// }
