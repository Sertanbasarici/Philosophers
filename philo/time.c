/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/06 19:54:34 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_current_time_in_msecond(void)
{
	struct timeval	time;
	int				control;

	control = gettimeofday(&time, NULL);
	if (control)
		ft_error(2);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long	ft_get_time(t_data *data)
{
	return (ft_current_time_in_msecond() - data->start_time);
}

int	smart_sleep(unsigned long time_pass)
{
	unsigned long	time_now;

	time_now = ft_current_time_in_msecond();
	while (ft_current_time_in_msecond() <= time_now + time_pass)
		usleep(100);
	return (0);
}

int	ft_ate_all(t_data *data)
{
	int			i;
	int			counter;
	static int	checker;

	if (checker == 1)
		return (1);
	counter = 0;
	i = 0;
	while (i < data->num_of_philo)
	{
		if (data->philo[i].meal_num == data->meal)
			counter++;
		i++;
	}
	if (counter == data->num_of_philo)
	{
		checker = 1;
		return (1);
	}
	return (0);
}
