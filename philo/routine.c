/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:28:53 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/04 14:46:35 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printer_locker(int a, t_philo *philo)
{
	pthread_mutex_lock(&(philo->program->write));
	if (a == 1)
		printf("%llu %d has taken a fork\n", current_time(philo), philo->id);
	else if (a == 2)
		printf("%llu %d is eating\n", current_time(philo), philo->id);
	else if (a == 3)
		printf("%llu %d is sleeping\n", current_time(philo), philo->id);
	else if (a == 4)
		printf("%llu %d is thinking\n", current_time(philo), philo->id);
	pthread_mutex_unlock(&(philo->program->write));
}

void	grap_forks(t_philo	*philo)
{
	pthread_mutex_lock(&(philo->fork));
	printer_locker(1, philo);
	pthread_mutex_lock(&(philo->next->fork));
	printer_locker(1, philo);
}

void	*routine(void *vd)
{
	t_philo	*philo;

	philo = (struct s_philo *)vd;
	if (philo->id % 2 == 0)
		u_sleep(philo->program->tte);
	while (1)
	{
		grap_forks(philo);
		pthread_mutex_lock(&philo->program->death);
		philo->last_eat = current_time(philo) + 0 * (philo->is_e)++;
		pthread_mutex_unlock(&philo->program->death);
		printer_locker(2, philo);
		u_sleep(philo->program->tte);
		pthread_mutex_lock(&philo->program->death);
		if (philo->program->notepme != -1)
			philo->hmtpe++;
		philo->is_e = 0;
		pthread_mutex_unlock(&philo->program->death);
		pthread_mutex_unlock(&(philo->fork));
		pthread_mutex_unlock(&(philo->next->fork));
		printer_locker(3, philo);
		u_sleep(philo->program->tts);
		printer_locker(4, philo);
	}
	return (NULL);
}

void	mutexes_destroyer(t_philo *philo, t_programm *program)
{
	pthread_mutex_destroy(&(philo)->fork);
	pthread_mutex_destroy(&(program->write));
	pthread_mutex_destroy(&(program->death));
	pthread_mutex_destroy(&(program)->time);
}
