/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:40 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/10 17:54:11 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int num, t_philo *philo)
{
	if (num == 0)
		write(2, "invalid number of arguments\n", 29);
	else if (num == 1)
		write(2, "Error has occured while creating threads\n", 42);
	else if (num == 2)
		write(2, "invalid entry\n",15);
	free(philo);
	exit(0);
}

int	main(int argn, char **argv)
{
	t_philo *philo;
	(void)argn;
	philo = malloc(sizeof(t_philo));
	if (argn != 6)
		ft_error(0, philo);
	ft_philo_starts(argv, philo); 
	ft_threads_init(philo);
	ft_mutex_init(philo);
}