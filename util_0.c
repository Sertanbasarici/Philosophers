/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:47:53 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/10 11:57:01 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_starts(char **argv, t_philo *philo)
{
	philo->num_of_philo = ft_atoi_adjusted(argv[1], philo);
	philo->time_to_die = ft_atoi_adjusted(argv[2], philo);
	philo->time_to_eat = ft_atoi_adjusted(argv[3], philo);
	philo->time_to_sleep = ft_atoi_adjusted(argv[4], philo);
	philo->meal = ft_atoi_adjusted(argv[5], philo);
	philo->time_to_think = philo->time_to_die - philo->time_to_sleep;
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
	philo->philo_th = malloc(sizeof(pthread_t) * philo->num_of_philo);
}

void	ft_mutex_init(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo -> num_of_philo)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		i++;
	}
}

void	ft_threads_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_create(&philo -> philo_th[i], NULL, &routine, NULL) != 0)
			ft_error(1, philo);
		i++;
	}
}