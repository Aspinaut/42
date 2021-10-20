/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 16:48:56 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/20 11:35:00 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	put_two_shortest_in_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	min;
	int	i;

	min = find_min(*stack_a);
	i = 0;
	// printf("FIRST \n");
	// printf("-----------------------------------------------------\n");
	// while (*stack_a)
	// {
	// 	printf("%d\n", (*stack_a)->nb);
	// 	if (!(*stack_a)->next)
	// 		break ;
	// 	*stack_a = (*stack_a)->next;
	// }
	// while (*stack_a && (*stack_a)->prev)
	// 	*stack_a = (*stack_a)->prev;
	// printf("-----------------------------------------------------\n");

	while (*stack_a && (*stack_a)->nb != min)
	{
		*stack_a = (*stack_a)->next;
		i++;
	}
	while (*stack_a && (*stack_a)->prev)
		*stack_a = (*stack_a)->prev;
	if (i == 0)
	{
		push_small(stack_b, (*stack_a)->nb, 'b');
	}
	else if (i == 1)
	{

		// printf("SECOND \n");
		// printf("-----------------------------------------------------\n");
		// while (*stack_a)
		// {
		// 	printf("%d\n", (*stack_a)->nb);
		// 	if (!(*stack_a)->next)
		// 	break ;
		// 	*stack_a = (*stack_a)->next;
		// }
		// while (*stack_a && (*stack_a)->prev)
		// *stack_a = (*stack_a)->prev;
		// printf("-----------------------------------------------------\n");
		// if ((*stack_a)->prev)
		// 	*stack_a = (*stack_a)->prev;
		swap(*stack_a, 'a');
		push_small(stack_b, (*stack_a)->nb, 'b');
	}
	else if (i == 2 && size == 5)
	{
		rotate(stack_a, 'a');
		swap(*stack_a, 'a');
		push_small(stack_b, (*stack_a)->nb, 'b');
	}
	else if ((i == 3 && size == 5) || (i == 2 && size == 4))
	{

		reverse_rotate(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
		push_small(stack_b, (*stack_a)->nb, 'b');
	}
	else if (i == 4 || (i == 3 && size == 4))
	{
		reverse_rotate(stack_a, 'a');
		push_small(stack_b, (*stack_a)->nb, 'b');
	}
	// while (*stack_a)
	// {
	// 	if (!(*stack_a)->next)
	// 		break ;
	// 	*stack_a = (*stack_a)->next;
	// }
	// while (*stack_a && (*stack_a)->prev)
	// 	*stack_a = (*stack_a)->prev;

	// *stack_a = (*stack_a)->next;
	stack_delone(stack_a, 0);


}

static void sort_three(t_stack **a)
{
	if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb \
	&& (*a)->nb < (*a)->next->next->nb)
	{
		swap(*a, 'a');
		rotate(a, 'a');
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb)
	{
		rotate(a, 'a');
		swap(*a, 'a');
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb \
	&& (*a)->nb > (*a)->next->next->nb)
		rotate(a, 'a');
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb \
	&& (*a)->nb < (*a)->next->next->nb)
		swap(*a, 'a');
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb \
	&& (*a)->nb > (*a)->next->next->nb)
		reverse_rotate(a, 'a');
}

static void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	stop;

	stop = -1;
	while (!sorted(*stack_a, 0) && ++stop < 2 && stack_size(*stack_a) > 3)
	{
		// printf("FIRST \n");
		// printf("-----------------------------------------------------\n");
		// while (*stack_a)
		// {
		// 		printf("%d\n", (*stack_a)->nb);
		// 		if (!(*stack_a)->next)
		// 		break ;
		// 		*stack_a = (*stack_a)->next;
		// 	}
		// 	while (*stack_a && (*stack_a)->prev)
		// 	*stack_a = (*stack_a)->prev;
		// 	printf("-----------------------------------------------------\n");
		put_two_shortest_in_b(stack_a, stack_b, stack_size(*stack_a));
	}

	// printf("BEFORE 3 : \n");
	// printf("-----------------------------------------------------\n");
	// printf("STACK A : \n");
	//
	// while (*stack_a)
	// {
	// 	printf("%d\n", (*stack_a)->nb);
	// 	*stack_a = (*stack_a)->next;
	// }
	// printf("-----------------------------------------------------\n");
	// printf("STACK B : \n");
	//
	// while (*stack_b)
	// {
	// 	printf("%d\n", (*stack_b)->nb);
	// 	*stack_b = (*stack_b)->next;
	// }
	// printf("-----------------------------------------------------\n");

	sort_three(stack_a);

	if (stack_b)
	{
		while ((*stack_b))
		{
			push_small(stack_a, (*stack_b)->nb, 'a');
			if (!(*stack_b)->next)
				break ;
			(*stack_b) = (*stack_b)->next;
		}
		stack_clear(stack_b);
	}
}

void	small_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2 && (*stack_a)->nb > (*stack_a)->next->nb)
		swap(*stack_a, 'a');
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, stack_b);
}
