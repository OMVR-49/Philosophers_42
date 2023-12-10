/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:28:53 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/02 12:18:15 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void printer_locker(int a, t_philo *philo, unsigned long long current_t)
{
	(void)current_t;
	if (a == 1)
	{
		pthread_mutex_lock(&(philo->program->write));
		printf("%llu %d has taken a fork\n", current_time(), philo->id);
		pthread_mutex_unlock(&(philo->program->write));
	}
	else if (a == 2)
	{
   		pthread_mutex_lock(&(philo->program->write));
		printf("%llu %d is eating\n", current_time(), philo->id);
		pthread_mutex_unlock(&(philo->program->write));
	}
	else if (a == 3)
	{
		pthread_mutex_lock(&(philo->program->write));
		printf("%llu %d is sleeping\n", current_time(), philo->id);
		pthread_mutex_unlock(&(philo->program->write));
	}
	else if (a == 4)
	{
		pthread_mutex_lock(&(philo->program->write));
		printf("%llu %d is thinking\n", current_time(), philo->id);
		pthread_mutex_unlock(&(philo->program->write));
	}
}

void release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&(philo->fork));
	pthread_mutex_unlock(&(philo->next->fork));
}

void eat_sleep_think(t_philo *philo, unsigned long long current_t)
{
    pthread_mutex_lock(&(philo->fork));
	printer_locker(1, philo, current_t);
    pthread_mutex_lock(&(philo->next->fork));
	printer_locker(1, philo, current_t);
	philo->last_eat = get_time();
	printer_locker(2, philo, current_t);
	u_sleep(philo->program->tte);
	release_forks(philo);
	printer_locker(3, philo, current_t);
	if(philo->program->notepme != -1)
		philo->how_much_this_philo_eat++;
	u_sleep(philo->program->tts);
	printer_locker(4, philo, current_t);
}


void *routine(void *vd)
{
	t_philo *philo;
	unsigned long long current_t;

	philo = (struct s_philo *)vd;
	if(philo->id % 2 != 0)
		u_sleep(philo->program->tte);
	current_t = get_time();
	while(!philo->program->dead && (philo->program->notepme == -1 ||
	philo->program->eaten_spag < philo->program->notepme))
	{
		printf("--------------\n");
		eat_sleep_think(philo, current_t);
		
	}
	return NULL;
}