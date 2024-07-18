/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:45:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/18 16:11:25 by sebasari         ###   ########.fr       */
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
	int				index_philo;
	int				index_fork;
	pthread_t		philo_th;
	pthread_mutex_t	fork;
}	t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_think;
	int				meal;
	unsigned long	start_time;
	t_philo			*philo;
}	t_data;

t_data			*ft_philo_refill(t_data *philo_ex);
void			ft_philo_starts(int argn, char **argv, t_data *data);
void			ft_error(int num, t_data *philo);
void			ft_threads_init(t_data *philo);
void			*routine(void *philo);
unsigned long	ft_current_time_in_msecond(t_data *philo);
int				ft_atoi_adjusted(const char *str, t_data *philo);
void			ft_threads_destroy(t_data *philo);
void			ft_mutex_destroy(t_data *philo);
unsigned long	ft_start_time(t_data *philo, unsigned long time);
int				ft_is_eating(t_data *philo);
void			ft_mutex_init(t_data *philo);

#endif