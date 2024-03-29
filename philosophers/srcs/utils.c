/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmasse <vmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:02:00 by vmasse            #+#    #+#             */
/*   Updated: 2022/01/04 14:48:47 by vmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_exit(int ret, char *err)
{
	write(2, err, ft_strlen(err));
	return (ret);
}

long int	time_now(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

int	ft_usleep(long int time)
{
	long int	start_time;

	start_time = time_now();
	while ((time_now() - start_time) < time)
		usleep(150);
	return (1);
}

void	print_status(t_phi *philos, char *status)
{
	pthread_mutex_lock(&philos->params->print);
	if (!philos->params->died)
		printf("%ldms %d %s\n", time_now() - philos->params->start_time,
			philos->id, status);
	pthread_mutex_unlock(&philos->params->print);
}
