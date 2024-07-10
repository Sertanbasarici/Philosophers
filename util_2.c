/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 18:21:43 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/10 18:42:47 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philo *philo)
{
	while (ft_time_in_msecond(philo) < philo->time_to_eat + ft_time_in_msecond(philo))
		usleep(100);
}

void	is_sleeping(t_philo *philo)
{
	while (ft_time_in_msecond(philo) < philo->time_to_sleep + ft_time_in_msecond(philo))
		usleep(100);
}