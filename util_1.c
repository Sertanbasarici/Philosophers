/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:41 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/22 17:23:09 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_adjusted(const char *str, t_data *philo)
{
	int	i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		ft_error(2, philo);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	if (result > 2147483647)
		ft_error(2, philo);
	return (result);
}

t_data	*ft_philo_refill(t_data *data_ex)
{
	t_data	*data;

	data = malloc(sizeof(t_philo));
	data->num_of_philo = data_ex->num_of_philo;
	data->time_to_die = data_ex->time_to_die;
	data->time_to_eat = data_ex->time_to_eat;
	data->time_to_sleep = data_ex->time_to_sleep;
	if (data_ex->meal == -1)
		data->meal = -1;
	else
		data->meal = data_ex->meal;
	data->time_to_think = data_ex->time_to_die - data_ex->time_to_sleep;
	data->philo = malloc(sizeof(t_philo) * data->num_of_philo);
	data = data_ex;
	return (data);
}

int	ft_find_index(t_philo *philo)
{
	static int	i;
	int			num;

	num = philo[i++].index_philo;
	return (num);
}

void	*routine(void *data_ex)
{
	t_data	*data;
	int		index;

	data = (t_data *)data_ex;
	data->start_time = ft_current_time_in_msecond(data);
	pthread_mutex_lock(&data->mutex);
	index = ft_find_index(data->philo);
	pthread_mutex_unlock(&data->mutex);
	while(1)
	{
		ft_is_eating(data, index);
		ft_is_sleeping(data, index);
		ft_is_thinking(data, index);
	}
	return NULL;
}