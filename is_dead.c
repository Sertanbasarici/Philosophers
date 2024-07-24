/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:38:18 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/24 20:16:16 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_dead(t_data *data, int before_eating, int after_eating, int index)
{
	pthread_mutex_lock(&data->mutex);
	if (after_eating - before_eating > (int)data->time_to_die)
	{
		printf("%lu	%d died\n", ft_get_time(data, data->start_time), data->philo[index].index_philo);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex);
	return (0);
}