/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:21:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/20 16:08:45 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc == 1)
		return (0);
	if (!validate_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2));
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	while (++i < argc)
		new_stack(&stack_a, ft_atoi(argv[i]));
	if (stack_size(stack_a) < 6 && stack_size(stack_a) > 1)
		small_sort(&stack_a, &stack_b, stack_size(stack_a));
	else
		big_sort(&stack_a, &stack_b);
	stack_clear(&stack_a);
	return (0);
}
