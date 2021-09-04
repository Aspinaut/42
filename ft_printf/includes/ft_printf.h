/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:58 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/04 09:10:19 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct  s_var
{
    va_list args;
    int     len;
}               t_var;

int     ft_printf(const char *s, ...);

void    ft_print_char(t_var *vartab);
void    ft_print_str(t_var *vartab);
void    ft_print_address(t_var *vartab);
void   ft_print_per(t_var *vartab);

void    ft_print_int(t_var *vartab);
void    ft_print_unsigned_int(t_var *vartab);
void    ft_print_hex_min(t_var *vartab);
void    ft_print_hex_maj(t_var *vartab);

void	ft_putnbr_unsigned(t_var *vartab, unsigned int n);
void	ft_putnbr(t_var *vartab, int n);
void ft_putnbr_hex(t_var *vartab, unsigned int nb, unsigned int converter);

#endif
