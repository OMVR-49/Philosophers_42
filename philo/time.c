/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:24:04 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/04 14:34:27 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_time(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

unsigned long long	current_time(t_philo *philo)
{
	static long long	t;

	pthread_mutex_lock(&philo->program->time);
	if (t == 0)
		t = get_time();
	pthread_mutex_unlock(&philo->program->time);
	return (get_time() - t);
}

void	u_sleep(unsigned long long tiime)
{
	unsigned long long	time;

	time = get_time();
	while (get_time() - time < tiime)
		usleep(500);
}
