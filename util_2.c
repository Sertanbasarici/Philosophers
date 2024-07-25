/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:21:43 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/25 20:41:34 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_eating(t_data *data, int index)
{
	if (ft_is_dead(data,data->philo[index].last_meal, ft_get_time(data, data->start_time), index) == 0)
	{
		pthread_mutex_lock(&data->fork[index]);
		ft_print_actions(data, index, "has taken a fork");
		pthread_mutex_lock(&data->fork[(index + 1) % data->num_of_philo]);
		ft_print_actions(data, index, "has taken a fork");
		ft_print_actions(data, index, "is eating");
		smart_sleep(data, data->time_to_eat);
		if (ft_is_dead(data, data->philo[index].last_meal, ft_get_time(data, data->start_time), index) == 1)
			return (1);
		data->philo[index].last_meal = ft_get_time(data, data->start_time);
		pthread_mutex_unlock(&data->fork[index]);
		pthread_mutex_unlock(&data->fork[(index + 1) % data->num_of_philo]);
		data->philo[index].meal_num++;
		return (0);
	}
	else
		return (1);

}

int	ft_is_sleeping(t_data *data, int index)
{
	ft_print_actions(data, index, "is sleeping");
	smart_sleep(data, data->time_to_sleep);
	if (ft_is_dead(data, data->philo[index].last_meal, ft_get_time(data, data->start_time), index) == 1)
		return (1);
	return (0);
}

int	ft_is_thinking(t_data *data, int index)
{
	pthread_mutex_lock(&data->mutex);
	ft_print_actions(data, index, "is thinking");
	pthread_mutex_unlock(&data->mutex);
	if (ft_is_dead(data, data->philo[index].last_meal, ft_get_time(data, data->start_time), index) == 1)
		return (1);
	return (0);
}

int	ft_is_dead(t_data *data, int before_eating, int after_eating, int index)
{
	pthread_mutex_lock(&data->mutex);
	if (after_eating - before_eating > (int)data->time_to_die)
	{
		ft_print_actions(data, index, "is dead");
		return (1);
	}
	pthread_mutex_unlock(&data->mutex);
	return (0);
}

void	ft_print_actions(t_data *data, int index, char *str)
{
	printf("%lu	%d %s\n", ft_get_time(data, data->start_time), data->philo[index].index_philo + 1, str);
}