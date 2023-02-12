/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:48:32 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/12 22:16:51 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(t_arg *args, char *argv[]);
int	check_args(t_arg *args);
int	init_philo(t_arg *args, t_pth **philo);
int	init_forks(t_arg *args);

int	init_args(t_arg *args, char *argv[])
{
	args->fork = NULL;
	args->start = get_time();
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->number_of_times_eat = -1;
	if (argv[5])
		args->number_of_times_eat = ft_atoi(argv[5]);
	pthread_mutex_init(&args->pen, NULL);
	pthread_mutex_unlock(&args->pen);
	return (check_args(args));
}

int	check_args(t_arg *args)
{
	if (args->number_of_philosophers < 2 || args->time_to_die <= 0
		|| args->time_to_eat <= 0 || args->time_to_sleep <= 0)
		return (ERROR);
	if (!args->number_of_philosophers)
		return (ERROR);
	return (SUCCESS);
}

int	init_philo(t_arg *args, t_pth **philo)
{
	int	i;

	i = 0;
	*philo = malloc(sizeof(t_pth) * args->number_of_philosophers);
	if (!philo)
		return (ERROR);
	while (i < args->number_of_philosophers)
	{
		(*philo)[i].arg = args;
		(*philo)[i].pth_id = i;
		(*philo)[i].count_eat = 0;
		(*philo)[i].l_fork = (i + 1) % args->number_of_philosophers;
		(*philo)[i].r_fork = i;
		if (args->number_of_times_eat)
			(*philo)[i].max_eat = args->number_of_times_eat;
		i++;
	}
	return (SUCCESS);
}

int	init_forks(t_arg *args)
{
	int	i;

	i = 0;
	args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* args->number_of_philosophers);
	if (!args->fork)
		return (ERROR);
	while (i < args->number_of_philosophers)
	{
		if (pthread_mutex_init(&(args->fork[i]), NULL))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
