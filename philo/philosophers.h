/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojebbari <ojebbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:11:59 by ojebbari          #+#    #+#             */
/*   Updated: 2023/10/04 14:29:29 by ojebbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_programm
{
	int						dead;
	int						nop;
	int						ttd;
	int						tte;
	int						tts;
	int						notepme;
	unsigned long long		curreent;
	pthread_mutex_t			write;
	pthread_mutex_t			death;
	pthread_mutex_t			time;
}	t_programm;

typedef struct s_philo
{
	pthread_t		ph;
	int				last_eat;
	int				hmtpe;
	int				id;
	int				is_e;
	pthread_mutex_t	fork;
	t_programm		*program;
	struct s_philo	*next;
}	t_philo;

void				printer_locker(int a, t_philo *philo);
void				creat_linked_list(t_philo **creat, t_programm *program);
void				mutexes_destroyer(t_philo *philo, t_programm *program);
void				ft_lstadd_back(t_philo **lst, t_philo *new);
void				u_sleep(unsigned long long tiime);
void				release_forks(t_philo *philo);
void				*routine(void *vd);
int					eat_sleep_think(t_philo *philo,
						unsigned long long current_t);
int					initialize(t_programm *program, char **av, int ac);
int					check_if_int_digit_and_positif(char *str);
int					check_dead_notepme(t_philo *philo);
int					ft_pa(int ac, char **av);
int					dead(t_philo *philo);
int					error(void);
t_philo				*ft_lstnew(int a, t_programm *x);
long long			ft_atoi(const char *str);
size_t				ft_strlen(const char *s);
unsigned long long	current_time(t_philo *philo);
unsigned long long	get_time(void);
#endif