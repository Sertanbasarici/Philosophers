/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:21:43 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/24 20:47:44 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_eating(t_data *data, int index)
{
	if (ft_is_dead(data, data->philo[index].before_last_meal, data->philo[index].before_last_meal + data->time_to_die, index) == 0)
	{
		pthread_mutex_lock(&data->fork[index]);
		printf("%lu %d has taken a fork\n", ft_get_time(data, data->start_time), data->philo[index].index_philo + 1);
		pthread_mutex_lock(&data->fork[(index + 1) % data->num_of_philo]);
		printf("%lu %d has taken a fork\n", ft_get_time(data, data->start_time), data->philo[index].index_philo + 1);
		printf("%lu %d is eating\n", ft_get_time(data, data->start_time), data->philo[index].index_philo + 1);
		smart_sleep(data, data->time_to_eat);
		data->philo[index].last_meal = ft_get_time(data, data->start_time);
		ft_is_dead(data, data->philo[index].before_last_meal, data->philo[index].last_meal, index);
		data->philo[index].before_last_meal = data->philo[index].last_meal;
		pthread_mutex_unlock(&data->fork[index]);
		pthread_mutex_unlock(&data->fork[(index + 1) % data->num_of_philo]);
		return (0);
	}
	else
		return (1);

}

int	ft_is_sleeping(t_data *data, int index)
{
	printf("%lu %d is sleeping\n",ft_get_time(data, data->start_time), data->philo[index].index_philo + 1);
	smart_sleep(data, data->time_to_sleep);
	return (0);
}

int	ft_is_thinking(t_data *data, int index)
{
	pthread_mutex_lock(&data->mutex);
	printf("%lu %d is thinking\n",ft_get_time(data, data->start_time), data->philo[index].index_philo + 1);
	pthread_mutex_unlock(&data->mutex);
	return (0);
}