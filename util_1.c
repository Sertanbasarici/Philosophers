/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:41 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/25 20:55:25 by sebasari         ###   ########.fr       */
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
		ft_error(3, philo);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	if (result > 2147483647)
		ft_error(3, philo);
	return (result);
}

void	ft_number_check(char **argv, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i][j])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				ft_error(2, data);
			j++;
		}
		i++;
	}
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
	pthread_mutex_lock(&data->mutex);
	index = ft_find_index(data->philo);
	pthread_mutex_unlock(&data->mutex);
	while (1)
	{
		if (data->meal != data->philo[index].meal_num)
		{
			if ((ft_is_eating(data, index) == 1 ) || (ft_is_dead(data, data->philo->last_meal, ft_get_time(data, data->start_time), index) == 1))
				break;
			if (ft_is_sleeping(data, index) || ft_is_dead(data, data->philo->last_meal, ft_get_time(data, data->start_time), index) == 1)
				break;
			if (ft_is_thinking(data, index) || ft_is_dead(data, data->philo->last_meal, ft_get_time(data, data->start_time), index) == 1)
				break;
		}
		else
			break ;
	}
	//ft_free(data);
 	//system("leaks ");
	return NULL;
}