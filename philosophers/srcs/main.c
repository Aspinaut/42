/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:51:42 by vmasse            #+#    #+#             */
/*   Updated: 2022/01/08 12:50:16 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	check_death(t_phi *philos, t_params *params, int last_to_eat)
{
	int	i;

	while (!philos->params->start)
		continue ;
	while (!params->died)
	{
		i = -1;
		while (++i < philos->params->philos)
		{
			if ((time_now() - philos[i].start_eating) > params->to_die)
			{
				print_status(philos, DIE);
				params->died = 1;
				if (params->philos == 1)
					pthread_mutex_unlock(philos[i].l_fork);
				break ;
			}
			if (params->eat_max && philos[last_to_eat].meals >= params->eat_max)
			{
				params->died = 1;
				break ;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_phi		*philos;
	int			last_to_eat;

	philos = NULL;
	if (argc != 5 && argc != 6)
		return (ft_exit(1, "Error\nWrong nb of arguments\n"));
	if (!init_params(&params, argv))
		return (ft_exit(1, "Failed to init params\n"));
	philos = init_philos(philos, &params);
	if (!philos)
		return (ft_exit(1, "Error\nFailed to init philos\n"));
	last_to_eat = params.philos - 1;
	if (params.philos % 2 != 0)
		last_to_eat -= 1;
	check_death(philos, &params, last_to_eat);
	free_philos(philos, &params);
	return (0);
}
