/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebasari <sebasari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:45:07 by sebasari          #+#    #+#             */
/*   Updated: 2024/08/06 18:05:16 by sebasari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				index_philo;
	unsigned long	last_meal;
	int				meal_num;
	pthread_t		philo_th;
}	t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				meal;
	unsigned long	start_time;
	pthread_t		dead;
	pthread_mutex_t	*fork;
	t_philo			*philo;
	pthread_mutex_t	mutex;
}	t_data;

int					ft_ate_all(t_data *data);
void				ft_free(t_data *data);
int					ft_only_one(t_data *data);
void				*routine_one(void *data_ex);
int					ft_number_check(char **argv);
int					ft_philo_starts(int argn, char **argv, t_data *data);
void				ft_error(int num);
int					ft_threads_init(t_data *philo);
void				*routine(void *philo);
unsigned long		ft_current_time_in_msecond(void);
unsigned long long	ft_atoi_adjusted(const char *str);
int					ft_threads_destroy(t_data *philo);
void				ft_mutex_destroy(t_data *philo);
unsigned long		ft_get_time(t_data *data);
int					ft_is_eating(t_data *philo, int index);
void				ft_mutex_init(t_data *philo);
int					ft_find_index(t_philo *philo);
int					smart_sleep(unsigned long time_pass);
int					ft_is_thinking(t_data *data, int index);
int					ft_is_sleeping(t_data *data, int index);
int					ft_is_dead(t_data *data, int before_eating,
						int after_eating, int index);
void				ft_print_actions(t_data *data, int index, char *str);
int					ft_number_check_1(char *str);
void				*routine_checker(void *data_ex);

#endif