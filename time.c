/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:57:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/10 18:26:20 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_time_in_msecond(t_philo *philo)
{
	struct	timeval time;
	int	control;
	control = gettimeofday(&time, NULL);
	if (control)
		ft_error(2, philo);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long	current_time()
{

}