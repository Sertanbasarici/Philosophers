/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:21:43 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/06 18:59:00 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_eating(t_data *data, int index)
{
	pthread_mutex_lock(&data->fork[index]);
	if (ft_is_dead(data, data->philo[index].last_meal,
			ft_get_time(data), index) || ft_ate_all(data))
		return (1);
	ft_print_actions(data, index, "has taken a fork");
	pthread_mutex_lock(&data->fork[(index + 1) % data->num_of_philo]);
	if (ft_is_dead(data, data->philo[(index + 1) % data->num_of_philo]
			.last_meal, ft_get_time(data), index) || ft_ate_all(data))
		return (1);
	ft_print_actions(data, index, "has taken a fork");
	ft_print_actions(data, index, "is eating");
	smart_sleep(data->time_to_eat);
	data->philo[index].last_meal = ft_get_time(data);
	pthread_mutex_unlock(&data->fork[index]);
	pthread_mutex_unlock(&data->fork[(index + 1) % data->num_of_philo]);
	data->philo[index].meal_num++;
	if (ft_ate_all(data) || ft_is_dead(data, data->philo[index]
			.last_meal, ft_get_time(data), index))
		return (1);
	return (0);
}

int	ft_is_sleeping(t_data *data, int index)
{
	if (ft_is_dead(data, data->philo[index].last_meal,
			ft_get_time(data), index))
		return (1);
	if (ft_ate_all(data))
		return (1);
	ft_print_actions(data, index, "is sleeping");
	smart_sleep(data->time_to_sleep);
	if (ft_ate_all(data))
		return (1);
	if (ft_is_dead(data, data->philo[index].last_meal,
			ft_get_time(data), index))
		return (1);
	return (0);
}

int	ft_is_thinking(t_data *data, int index)
{
	if (ft_is_dead(data, data->philo[index].last_meal,
			ft_get_time(data), index) == 1)
		return (1);
	if (ft_ate_all(data))
		return (1);
	ft_print_actions(data, index, "is thinking");
	if (ft_is_dead(data, data->philo[index].last_meal,
			ft_get_time(data), index) == 1)
		return (1);
	if (ft_ate_all(data))
		return (1);
	return (0);
}

int	ft_is_dead(t_data *data, int before_eating, int after_eating, int index)
{
	static int	checker;

	pthread_mutex_lock(&data->mutex);
	if (checker == 1)
	{
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	if (after_eating - before_eating >= (int)data->time_to_die)
	{
		checker = 1;
		pthread_mutex_unlock(&data->mutex);
		ft_print_actions(data, index, "is dead");
		return (1);
	}
	pthread_mutex_unlock(&data->mutex);
	return (0);
}

void	ft_print_actions(t_data *data, int index, char *str)
{
	pthread_mutex_lock(&data->mutex);
	printf("%lu	%d %s\n", ft_get_time(data),
		data->philo[index].index_philo + 1, str);
	pthread_mutex_unlock(&data->mutex);
}
