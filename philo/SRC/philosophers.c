/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:11:57 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/02 12:17:57 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_parsing(int ac, char **av)
{
	int	i;

	i = 1;
	while(i < ac)
	{
		if (check_if_int_digit_and_positif(av[i]) == -1)
		{	
			if(i == 5 && ft_atoi(av[i]) == 0)
				break;
			else
				return(1);
		}
		i++;
	}
	if (ft_atoi(av[1]) > 200)
		return (1);
	return(0);
}

int main(int ac, char **av)
{
	pthread_t 		ph;
	t_programm		*program;
	t_philo			*philo;
	int				a;

	a = 1;
	program = malloc(sizeof(t_programm));
	if(!program)
		return(1);
	if ((ac != 5 && ac != 6) || ft_parsing(ac, av) || initialize(program, av, ac))
		return(error());
	creat_linked_list(&philo, program);
	while(a <= program->nop)
	{
		pthread_create(&ph, NULL, routine, philo);
		philo = philo->next;
		a++;
	}
	// monitro();
	return(0);
}






	// while(philo)
	// {
	// 	printf("[%d] : philo id\n", philo->id);
	// 	printf("%d number of philo\n", philo->program->nop);
	// 	printf("%d time to die\n", philo->program->ttd);
	// 	printf("%d time to eat\n", philo->program->tte);
	// 	printf("%d time to sleep\n", philo->program->tts);
	// 	printf("%d time each philo must eat\n", philo->program->notepme);
	// 	philo = philo->next;
	// sleep(1);
	// }