/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:40:32 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/04 14:34:41 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead_notepme(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->program->nop)
	{
		pthread_mutex_lock(&philo->program->death);
		if ((((int)current_time(philo) - philo->last_eat) > philo->program->ttd)
			&& !philo->is_e)
		{
			pthread_mutex_lock(&philo->program->write);
			printf("%llu %d has died\n", current_time(philo), philo->id);
			return (1);
		}
		if (philo->program->notepme != -1
			&& philo->hmtpe > philo->program->notepme)
			return (1);
		pthread_mutex_unlock(&philo->program->death);
		i++;
		philo = philo->next;
	}
	return (0);
}
