/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:21:16 by vmasse            #+#    #+#             */
/*   Updated: 2021/09/21 13:19:58 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	int i;

	if (argc < 2 || !validate_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2));
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
