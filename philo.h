/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:45:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/10 17:58:00 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_philo
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_think;
	int				meal;
	pthread_t		*philo_th;
	pthread_mutex_t	*fork;
}	t_philo;

void			ft_philo_starts(char **argv, t_philo *philo);
void			ft_error(int num, t_philo *philo);
void			ft_threads_init(t_philo *philo);
void			*routine();
unsigned long	ft_time_in_msecond(t_philo *philo);
int				ft_atoi_adjusted(const char *str, t_philo *philo);
void			ft_mutex_init(t_philo *philo);

#endif