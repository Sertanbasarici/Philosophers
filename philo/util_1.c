/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:41 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/30 00:55:13 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi_adjusted(const char *str)
{
	int					i;
	unsigned long long	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		ft_error(3);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result += str[i] - '0';
		i++;
	}
	if (result == 0)
		ft_error(3);
	if (result > 2147483647)
		ft_error(3);
	return (result);
}

int	ft_number_check_1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_number_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_number_check_1(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
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
		if (ft_ate_all(data)
			|| (ft_is_dead(data, data->philo[index].last_meal,
					ft_get_time(data), index)) || (ft_is_eating(data, index)))
			break ;
		if (ft_ate_all(data)
			|| ft_is_dead(data, data->philo[index].last_meal,
				ft_get_time(data), index) || (ft_is_sleeping(data, index)))
			break ;
		if (ft_ate_all(data)
			|| ft_is_dead(data, data->philo[index].last_meal,
				ft_get_time(data), index) == 1)
			break ;
		if (ft_ate_all(data))
			break ;
	}
	return (NULL);
}
