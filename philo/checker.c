/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:15:08 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/30 17:24:06 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_checker(void *data_ex)
{
	t_data	*data;
	int		index;

	data = (t_data *)data_ex;
	index = 0;
	while (1)
	{
		if (ft_is_dead(data, data->philo[index].last_meal, ft_get_time(data), index) || ft_ate_all(data))
			break ;
		if (ft_ate_all(data))
			break ;
		index = 0;
		while (index < data->num_of_philo)
		{
			if (ft_ate_all(data))
				break ;
			if (ft_is_dead(data, data->philo[index].last_meal, ft_get_time(data), index))
				break ;
		}
	}
	return (NULL);
}