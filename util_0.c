/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:47:53 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/10 11:57:01 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_starts(int argn, char **argv, t_data *data)
{
	data->num_of_philo = ft_atoi_adjusted(argv[1], data);
	data->time_to_die = ft_atoi_adjusted(argv[2], data);
	data->time_to_eat = ft_atoi_adjusted(argv[3], data);
	data->time_to_sleep = ft_atoi_adjusted(argv[4], data);
	if (argn == 6)
		data->meal = ft_atoi_adjusted(argv[5], data);
	else
		data->meal = -1;
	data->time_to_think = data->time_to_die - data->time_to_sleep;
	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
}

void	ft_mutex_init(t_data *data)
{
	int i;

	i = 0;
	while (i < data -> num_of_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		data->fork_index = i;
		i++;
	}
	pthread_mutex_init(&data->mutex, NULL);
}

void	ft_threads_init(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philo[i].index_philo = i;
		data->philo[i].last_meal = 0;
		data->philo[i].before_last_meal = 0;
		if (pthread_create(&data->philo[i++].philo_th, NULL, &routine, data) != 0)
			ft_error(1, data);
		usleep(200);
	}
}

void	ft_threads_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(data->philo[i].philo_th, NULL) != 0)
			ft_error(1, data);
		i++;
	}
}

void	ft_mutex_destroy(t_data *data)
{
	int i;

	i = 0;
	while (i < data -> num_of_philo)
	{
		pthread_mutex_destroy(data->fork);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
}
