/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:21:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/08 12:44:15 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	if (argc == 1)
		return (0);
	if (!validate_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2));
	stack_a = stack_addnew(ft_atoi(argv[1]));
	stack_b = NULL;
	if (!stack_a)
		return (-1);
	i = 1;
	while (++i <= (argc - 1))
		stack_addback(&stack_a->next, stack_addnew(ft_atoi(argv[i])));

	// small_sort(&stack_a, &stack_b, stack_size(stack_a));

	big_sort(&stack_a, &stack_b);

	while (stack_a)
	{
		printf("%d %d\n", stack_a->nb, stack_a->pos);
		stack_a = stack_a->next;
	}

	stack_clear(&stack_a);
	return (0);
}
