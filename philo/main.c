/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:40 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/09 12:45:01 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int num)
{
	if (num == 0)
		write(2, "invalid number of arguments\n", 29);
	else if (num == 1)
		write(2, "invalid entry\n", 15);
	else if (num == 2)
		write(2, "Error has occured while creating threads\n", 42);
	else if (num == 3)
		write(2, "invalid entry\n", 15);
}

int	main(int argn, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argn < 5 || argn > 6)
	{
		ft_error(0);
		free(data);
		return (1);
	}
	if (ft_number_check(argv) == 1)
	{
		ft_error(1);
		free(data);
		return (2);
	}
	if (ft_philo_starts(argn, argv, data) == 1)
	{
		ft_free(data);
		return (0);
	}
	ft_mutex_init(data);
	ft_threads_init(data);
	ft_threads_destroy(data);
	ft_mutex_destroy(data);
	ft_free(data);
}

void	ft_free(t_data *data)
{
	free(data->philo);
	free(data->fork);
	free(data);
}
