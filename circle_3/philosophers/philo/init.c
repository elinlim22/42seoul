/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:45:25 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/01 21:37:07 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_all *args, t_pth **philo)
{
	int	i;

	i = 0;
	*philo = (t_pth *)malloc(sizeof(t_pth) * args->number_of_philosophers);
	if (!philo)
		return (ERROR);
	while (i < args->number_of_philosophers)
	{
		(*philo)[i].count_eat = 0;
		(*philo)[i].l_fork = (i + 1) % args->number_of_philosophers;
		(*philo)[i].r_fork = i;
		(*philo)[i].pth = i;
		if (args->number_of_times_each_philosopher_must_eat)
			(*philo)[i].max_eat
				= args->number_of_times_each_philosopher_must_eat; //line too long : 변수명 수정 필요
		i++;
	}
	return (SUCCESS);
}

int	init_args(t_all *args, char *argv[])
{
	// memset(args, 0, )
	args->fork = NULL;
	args->number_of_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->number_of_times_each_philosopher_must_eat = 0;
	if (argv[5])
		args->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	return (check_args(args));
}

int	check_args(t_all *args)
{
	if (args->number_of_philosophers < 2 || args->time_to_die <= 0
		|| args->time_to_eat <= 0 || args->time_to_sleep <= 0)
		return (ERROR);
	if (!args->number_of_philosophers)
		return (ERROR);
	return (SUCCESS);
}

int	init_forks(t_all *args, t_pth **philo)
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
