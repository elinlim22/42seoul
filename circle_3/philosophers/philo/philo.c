/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:35:41 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/12 18:01:07 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_all *args, t_pth **philo);
int		timestamp(t_pth *philo, char *status);
void	monitor(t_pth **philo, t_all *args);
void	*monitor_limit(void *philo_v);

void	start_philos(t_all *args, t_pth **philo)
{
	pthread_t	mommy;
	int			i;

	i = 0;
	if (args->number_of_times_each_philosopher_must_eat)
	{
		if (pthread_create(&mommy, NULL, monitor_limit, philo))
		{
			ft_error("Mommy create error\n");
			return ;
		}
		pthread_detach(mommy);
	}
	while (i < args->number_of_philosophers)
	{
		if (pthread_create(&((*philo)[i].pth), NULL, dinner_time, &((*philo)[i])))
		{
			ft_error("Pthread create error\n");
			return ;
		}
		pthread_detach((*philo)[i].pth);
		i++;
	}
	monitor(philo, args);
}

//출력 모듈
int	timestamp(t_pth *philo, char *status)
{
	pthread_mutex_lock(&(philo->args->pen));
	printf("%lld\t", get_time() - philo->args->start);
	printf("%d %s\n", philo->pth_id, status);
	pthread_mutex_unlock(&(philo->args->pen));
	return (SUCCESS);
}

void	monitor(t_pth **philo, t_all *args)
{
	uint64_t	now;
	int			i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		now = get_time();
		if (now - philo[i]->last_eat >= (uint64_t)(args->time_to_die))
		{
			timestamp(philo[i], "died");
			return ;
		}
		i++;
	}
}

void	*monitor_limit(void *philo_v)
{
	// t_pth	*philo;

	// philo = (t_pth *)philo_v;
	// uint64_t	now;
	// int			i;

	// i = 0;
	// while (i < args->number_of_philosophers)
	// {
	// 	now = get_time();
	// 	if (now - (*philo)[i].last_eat >= args->time_to_die)
	// 	{
	// 		timestamp(&(*philo)[i], "died");
	// 		return ;
	// 	}
	// 	i++;
	// }
	(void)philo_v;
	return (NULL);
}
