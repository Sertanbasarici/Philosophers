/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:47:53 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/30 01:36:41 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_starts(int argn, char **argv, t_data *data)
{
	data->num_of_philo = ft_atoi_adjusted(argv[1]);
	data->time_to_die = ft_atoi_adjusted(argv[2]);
	data->time_to_eat = ft_atoi_adjusted(argv[3]);
	data->time_to_sleep = ft_atoi_adjusted(argv[4]);
	if (argn == 6)
		data->meal = ft_atoi_adjusted(argv[5]);
	else
		data->meal = -1;
	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_of_philo);
	data->start_time = ft_current_time_in_msecond();
	if (data->num_of_philo == 1)
	{
		if (ft_only_one(data) == 1)
			return (1);
	}
	return (0);
}

void	ft_mutex_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data -> num_of_philo)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex, NULL);
}

int	ft_threads_init(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->num_of_philo)
	{
		data->philo[i].index_philo = i;
		data->philo[i].last_meal = 0;
		data->philo[i].meal_num = 0;
		if (pthread_create(&data->philo[i++].philo_th,
				NULL, &routine, data) != 0)
		{
			ft_error(2);
			return (1);
		}
		usleep(100);
	}
	return (0);
}

int	ft_threads_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
	{
		if (pthread_join(data->philo[i].philo_th, NULL) != 0)
		{
			ft_error(2);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_mutex_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data -> num_of_philo)
	{
		pthread_mutex_destroy(data->fork);
		i++;
	}
	pthread_mutex_destroy(&data->mutex);
}
