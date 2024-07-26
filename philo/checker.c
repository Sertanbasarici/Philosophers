/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:07:23 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/26 19:26:40 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*checker(void *data_ex)
{
	t_data	*data;
	int		index;

	index = 0;
	data = data_ex;
	while (1)
	{
		while (index < data->num_of_philo)
		{
			if (ft_is_dead(data, data->philo[index].last_meal,
					ft_get_time(data, data->start_time), index) == 1)
				return (NULL);
			if (data->meal == data->philo[data->num_of_philo - 1].meal_num)
				return (NULL);
			index++;
		}
		index = 0;
	}
	return (NULL);
}

void	ft_free(t_data *data)
{
	free(data->philo);
	free(data->fork);
	free(data);
}
