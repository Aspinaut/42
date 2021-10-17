/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:21:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/17 11:34:05 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_spaces(char **argv)
{
	int i;
	int j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// void	fill_stack(t_stack **stack_a, int argc, char **argv)
// {
// 	int i;
//
// 	stack_a = stack_addnew(ft_atoi(argv[1]));
// 	if (!stack_a)
// 		return ;
// 	i = 1;
// 	while (++i <= (argc - 1))
// 		stack_addback(&stack_a->next, stack_addnew(ft_atoi(argv[i])));
// }

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	if (argc == 1)
		return (0);
	stack_a = stack_addnew(ft_atoi(argv[1]));
	if (!stack_a)
		return (-1);
	if (!validate_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2));

	stack_b = NULL;
	i = 1;
	while (++i < argc)
		stack_addback(&stack_a->next, stack_addnew(ft_atoi(argv[i])));

	// small_sort(&stack_a, &stack_b, stack_size(stack_a));
	big_sort(&stack_a, &stack_b);

	// while (stack_a)
	// {
	// 	printf("%d %d\n", stack_a->nb, stack_a->pos);
	// 	stack_a = stack_a->next;
	// }


	stack_clear(&stack_a);
	return (0);
}
