/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:48:49 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/29 17:18:26 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_only_one(t_data *data)
{
	data->philo[0].last_meal = data->time_to_eat;
	if (pthread_create(&data->philo[0].philo_th, NULL, &routine_one, data) != 0)
		ft_error(1);
	if (pthread_join(data->philo[0].philo_th, NULL) != 0)
		ft_error(1);
	return (1);
}

void	*routine_one(void *data_ex)
{
	t_data	*data;

	data = (t_data *)data_ex;
	ft_print_actions(data, 0, "has taken a fork");
	printf("%lu	%d is dead\n", ft_get_time(data) + data->time_to_die, 1);
	return (NULL);
}
