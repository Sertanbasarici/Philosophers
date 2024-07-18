/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/18 16:01:42 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_current_time_in_msecond(t_data *philo)
{
	struct	timeval time;
	int	control;

	control = gettimeofday(&time, NULL);
	if (control)
		ft_error(2, philo);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long	ft_start_time(t_data *philo, unsigned long time)
{
	return (ft_current_time_in_msecond(philo) - time);
}
