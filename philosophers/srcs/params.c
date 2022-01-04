/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:02:59 by vmasse            #+#    #+#             */
/*   Updated: 2022/01/04 23:18:55 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	check_args(t_params *params)
{
	if (params->philos < 1 || params->philos > INT_MAX)
		return (ft_exit(0, "Error\nWrong number of philos\n"));
	if (params->to_die < 1 || params->to_die > INT_MAX)
		return (ft_exit(0, "Error\nWrong time to die\n"));
	if (params->to_eat < 1 || params->to_eat > INT_MAX)
		return (ft_exit(0, "Error\nWrong time to eat\n"));
	if (params->to_sleep < 1 || params->to_sleep > INT_MAX)
		return (ft_exit(0, "Error\nWrong time to sleep\n"));
	if (params->eat_max < 1 || params->eat_max > INT_MAX)
		return (ft_exit(0, "Error\nWrong eat max\n"));
	return (1);
}

int	init_params(t_params *params, char **argv)
{
	params->philos = ft_atoi(argv[1]);
	params->to_die = ft_atoi(argv[2]);
	params->to_eat = ft_atoi(argv[3]);
	params->to_sleep = ft_atoi(argv[4]);
	params->start = 0;
	params->died = 0;
	pthread_mutex_init(&params->print, NULL);
	if (argv[5])
		params->eat_max = ft_atoi(argv[5]);
	else
		params->eat_max = 0;
	return (check_args(params));
}
