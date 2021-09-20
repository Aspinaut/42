/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:21:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/20 18:14:27 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args(char **argv)
{
	int i;
	int j;

	if (!argv)
		return (0);
	i = 0;
	while (argv[++i])
	{
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (0);
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	int i;

	if (argc < 2 || !check_args(argv))
		return (ft_putstr_fd("Error\n", 2));

	// check is_digit
	// bigger than int
	// duplicate args

	stack_a = stack_addnew(ft_atoi(argv[1]));
	i = 1;
	while (++i <= (argc - 1))
		stack_addback(&stack_a->next, stack_addnew(ft_atoi(argv[i])));

	// while (stack_a)
	// {
	// 	printf("%d\n", stack_a->nb);
	// 	stack_a = stack_a->next;
	// }

	return (0);
}
