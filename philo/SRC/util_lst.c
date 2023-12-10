/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:07:43 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/04 14:30:25 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo	*ft_lstnew(int a, t_programm *x)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (!node)
		return (0);
	pthread_mutex_init(&node -> fork, NULL);
	node->id = a;
	node->program = x;
	node->last_eat = 0;
	node->hmtpe = 0;
	node->is_e = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*oho;

	if (lst)
		oho = *lst;
	if (!lst || *lst == NULL)
		*lst = new;
	else
	{
		while (oho->next != NULL)
			oho = oho->next;
		oho->next = new;
	}
}

void	creat_linked_list(t_philo **creat, t_programm *program)
{
	t_philo	*temp; 
	int		a;

	a = 1;
	while (a <= program->nop)
	{
		temp = ft_lstnew(a, program);
		ft_lstadd_back(creat, temp);
		a++;
	}
	temp->next = *creat;
}
