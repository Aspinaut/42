/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:04:48 by vmasse            #+#    #+#             */
/*   Updated: 2021/10/13 16:20:41 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*add_nb_to_arr(int *nbs, int nb, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
		i++;
	nbs[i] = nb;
	return (nbs);
}

static int	is_duplicate(int *nbs, int nb, int pos)
{
	int	i;

	i = -1;
	while (++i < pos)
		if (nbs[i] == nb)
			return (1);
	return (0);
}

static int	process_checking(char *argv, int *nbs, int i)
{
	int	j;

	if (ft_atol(argv) > INT_MAX || ft_atol(argv) < INT_MIN)
		return (0);
	j = 0;
	if (argv[j] == '-' || argv[j] == '+')
		j++;
	while (argv[j])
	{
		if (!ft_isdigit(argv[j]))
			return (0);
		j++;
	}
	nbs = add_nb_to_arr(nbs, ft_atoi(argv), i - 1);
	if (is_duplicate(nbs, ft_atoi(argv), i - 1))
		return (0);
	return (1);
}

int	validate_args(int argc, char **argv)
{
	int	*nbs;
	int	i;

	if (!argv)
		return (0);
	i = 0;
	nbs = (int *)malloc(sizeof(int) * argc);
	if (!nbs)
		return (0);
	nbs[argc - 1] = 0;
	while (argv[++i])
	{
		if (!process_checking(argv[i], nbs, i))
		{
			free(nbs);
			return (0);
		}
	}
	free(nbs);
	return (1);
}
