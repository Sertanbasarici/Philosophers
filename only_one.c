/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:48:49 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/25 19:28:20 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_only_one(t_data *data)
{
	pthread_mutex_init(data->fork, NULL);
	data->philo[0].last_meal = data->time_to_eat;
	if (pthread_create(&data->philo[0].philo_th, NULL, &routine_one, data))
		ft_error(1, data);
	if (pthread_join(data->philo[0].philo_th, NULL))
		ft_error(1, data);
	pthread_mutex_destroy(data->fork);
}

void	*routine_one(void *data_ex)
{
	t_data *data;

	data = (t_data *)data_ex;
	pthread_mutex_lock(data->fork);
	ft_print_actions(data, 0, "has taken a fork");
	smart_sleep(data, data->time_to_eat);
	ft_print_actions(data, 0, "is dead");
	free(data->philo);
	free(data->fork);
	free(data);
	exit(0);
	return NULL;
}