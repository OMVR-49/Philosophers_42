/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:11:57 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/04 14:40:59 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_pa(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_if_int_digit_and_positif(av[i]) == -1)
		{
			if (i == 5 && ft_atoi(av[i]) == 0)
				break ;
			else
				return (1);
		}
		i++;
	}
	if (ft_atoi(av[1]) > 200)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_programm		*program;
	t_philo			*philo;
	int				a;

	a = 0;
	program = malloc(sizeof(t_programm));
	if (!program)
		return (1);
	if ((ac != 5 && ac != 6) || ft_pa(ac, av) || initialize(program, av, ac))
		return (error());
	creat_linked_list(&philo, program);
	philo->program->curreent = get_time();
	while (++a <= program->nop)
	{
		pthread_create(&philo->ph, NULL, routine, philo);
		pthread_detach(philo->ph);
		philo = philo->next;
	}
	while (1)
	{
		if (check_dead_notepme(philo))
			break ;
	}
	return (mutexes_destroyer(philo, program), free(program), 0);
}
