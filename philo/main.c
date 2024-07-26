/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:44:40 by sebasari          #+#    #+#             */
/*   Updated: 2024/07/26 19:16:20 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(int num, t_data *data)
{
	if (num == 0)
	{
		write(2, "invalid number of arguments\n", 29);
		free(data);
	}
	else if (num == 1)
	{
		write(2, "invalid entry\n", 15);
		free(data);
	}
	else if (num == 2)
	{
		write(2, "Error has occured while creating threads\n", 42);
		ft_free(data);
	}
	else if (num == 3)
	{
		write(2, "invalid entry\n", 15);
		ft_free(data);
	}
	exit(0);
}

int	main(int argn, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argn < 5 || argn > 6)
		ft_error(0, data);
	ft_number_check(argv, data);
	ft_philo_starts(argn, argv, data);
	ft_mutex_init(data);
	ft_threads_init(data);
	ft_threads_destroy(data);
	ft_mutex_destroy(data);
	ft_free(data);
}

/*__attribute__((destructor)) static void test()
{
	system("leaks philo");
}*/