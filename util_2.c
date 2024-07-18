/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:21:43 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/18 20:29:41 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_eating(t_data *data)
{
	static	int		i;
	unsigned long	time_holder;

	i = 0;
	time_holder = ft_start_time(data, data->start_time);
	pthread_mutex_lock(&data->philo[data->num_of_philo % 2].fork);
	printf("%lu %d has taken a fork\n", time_holder, data->philo[data->num_of_philo % 2].index_philo + 1);
	pthread_mutex_lock(&data->philo[data->num_of_philo % 2 + 1].fork);
	printf("%lu %d has taken a fork\n", time_holder, data->philo[data->num_of_philo % 2].index_philo + 1);
	while (ft_start_time(data, data->start_time) < time_holder + data->time_to_eat)
		usleep(100);
	pthread_mutex_unlock(&data->philo[data->num_of_philo % 2].fork);
	pthread_mutex_unlock(&data->philo[data->num_of_philo % 2 + 1].fork);
	return (1);
}
