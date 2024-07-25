/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:48:49 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/26 01:53:39 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_only_one(t_data *data)
{
	data->philo[0].last_meal = data->time_to_eat;
	if (pthread_create(&data->philo[0].philo_th, NULL, &routine_one, data) != 0)
		ft_error(1, data);
	if (pthread_join(data->philo[0].philo_th, NULL) != 0)
		ft_error(1, data);
}

void	*routine_one(void *data_ex)
{
	t_data *data;

	data = (t_data *)data_ex;
	ft_print_actions(data, 0, "has taken a fork");
	smart_sleep(data, data->time_to_eat);
	ft_print_actions(data, 0, "is dead");
	free(data->philo);
	free(data->fork);
	free(data);
	return NULL;
}