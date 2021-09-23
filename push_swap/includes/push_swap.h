/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:21:41 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/23 08:51:32 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// to clean
# include "stdio.h"

# include <limits.h>
# include "./libft.h"

typedef struct s_stack
{
	int	nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

t_stack	*stack_addnew(int nb);
void	stack_addback(t_stack **stack, t_stack *new);
void	stack_addfront(t_stack **stack, t_stack *new);
void	stack_delone(t_stack *stack, void (*del)(int));
void	stack_clear(t_stack **stack);
int	stack_size(t_stack *stack);

int	validate_args(int argc, char **argv);
void swap(t_stack **stack, char c);

#endif
