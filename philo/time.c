/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/26 18:29:37 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_current_time_in_msecond(t_data *data)
{
	struct timeval	time;
	int				control;

	control = gettimeofday(&time, NULL);
	if (control)
		ft_error(2, data);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long	ft_get_time(t_data *data, unsigned long time)
{
	return (ft_current_time_in_msecond(data) - time);
}

void	smart_sleep(t_data *data, unsigned long time_pass)
{
	unsigned long	time_now;

	time_now = ft_current_time_in_msecond(data);
	while (ft_current_time_in_msecond(data) <= time_now + time_pass)
	{
		usleep(100);
	}
}
