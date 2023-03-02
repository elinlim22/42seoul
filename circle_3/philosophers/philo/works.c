/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   works.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 20:40:12 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/12 17:55:17 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*dinner_time(void *philo_v);
void	routine(t_all *args, t_pth *philo);
// void	sleep_time(t_pth **philo);

//비둘기야 밥먹자 구구구구ㅜㄱ구ㅜ
void	*dinner_time(void *philo_v)
{
	t_pth	*philo;

	philo = (t_pth *)philo_v;
	// pthread_t	mommy;

	// if (pthread_create(&mommy, NULL, monitor, (*philo)))
	// {
	// 	ft_error("Mommy create error\n");
	// 	return (NULL);
	// }
	// pthread_detach(mommy);
	routine(philo->args, philo);
	return ((void *)SUCCESS);
}

void	routine(t_all *args, t_pth *philo)
{
	while (1)
	{
		pthread_mutex_lock(&(args->fork[philo->l_fork]));
		timestamp(philo, "has taken a fork");
		pthread_mutex_lock(&(args->fork[philo->r_fork]));
		timestamp(philo, "has taken a fork");
		timestamp(philo, "is eating");
		usleep(1000 * args->time_to_eat);
		philo->last_eat = get_time(); //
		philo->count_eat++;
		timestamp(philo, "is sleeping");
		pthread_mutex_unlock(&(args->fork[philo->l_fork]));
		pthread_mutex_unlock(&(args->fork[philo->r_fork]));
		usleep(1000 * args->time_to_sleep);
		timestamp(philo, "is thinking");
	}
}

// void	sleep_time(t_pth **philo)
// {
// 	timestamp(philo, "is sleeping");
// 	pthread_mutex_unlock(&(*philo)->args->fork[(*philo)->l_fork]);
// 	pthread_mutex_unlock(&(*philo)->args->fork[(*philo)->r_fork]);
// 	usleep(1000 * (*philo)->args->time_to_sleep);
// 	timestamp(philo, "is thinking");
// }
