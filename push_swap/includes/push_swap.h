/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:21:41 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/20 19:59:28 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	int					nb;
	int					pos;
	struct s_stack		*prev;
	struct s_stack		*next;
}				t_stack;

void	new_stack(t_stack **a, int value);
t_stack	*stack_last(t_stack *stack);
void	stack_addback(t_stack **stack, t_stack *new, t_stack *head);
void	stack_addfront(t_stack **stack, t_stack *new);
void	stack_delone(t_stack **stack, int big_sort);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*stack_cpy(t_stack *stack);

int		validate_args(int argc, char **argv);
void	swap(t_stack *stack, char c);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack **s, int nb, char c);
void	push_small(t_stack **stack, int nb, char c);
void	rotate(t_stack **stack, char c);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate(t_stack **stack, char c);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void	small_sort(t_stack **stack_a, t_stack **stack_b, int size);
void	big_sort(t_stack **stack_a, t_stack **stack_b);

int		find_min(t_stack *stack);
int		sorted(t_stack *stack, int big_sort);
void	quicksort(t_stack *stack_a, t_stack *head);
int		find_spaces(char **argv);

#endif
