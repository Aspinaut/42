/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:03:58 by vmasse            #+#    #+#             */
/*   Updated: 2021/08/17 16:03:17 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct  s_var
{
    va_list args;
    int     len_to_print;
}               t_var;

int     ft_printf(const char *s, ...);

void    ft_print_char(t_var *vartab);
void    ft_print_str(t_var *vartab);
void    ft_print_address(t_var *vartab);

void    ft_print_int(t_var *vartab);

#endif
