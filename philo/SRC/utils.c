/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:56:56 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/04 03:15:29 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	error(void)
{
	printf("THERE IS AN ERRoR\n");
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

long long	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long long			res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[0] == '\0')
		return (-1);
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	check_if_int_digit_and_positif(char *str)
{
	if (ft_atoi(str) <= 0)
		return (-1);
	else
		return (0);
}

int	initialize(t_programm *program, char **av, int ac)
{
	pthread_mutex_init(&program->write, NULL);
	pthread_mutex_init(&program->death, NULL);
	pthread_mutex_init(&program->time, NULL);
	program->nop = ft_atoi(av[1]);
	program->ttd = ft_atoi(av[2]);
	program->tte = ft_atoi(av[3]);
	program->tts = ft_atoi(av[4]);
	if (ac == 6)
		program->notepme = ft_atoi(av[5]);
	else
		program->notepme = -1;
	program->dead = 0;
	return (0);
}
