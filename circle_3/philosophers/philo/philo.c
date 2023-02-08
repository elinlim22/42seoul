/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:35:41 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/08 20:58:12 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_all *args, t_pth **philo)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		if (pthread_create((*philo)[i].pth, NULL, dinner_time, &((*philo)[i])))
		{
			ft_error("Pthread create error\n");
			return ;
		}
		i++;
	}
	monitor(args, philo);
}

long long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

//출력 모듈
int	timestamp(t_pth **philo, char *status)
{
	pthread_mutex_lock(&(*philo)->args->pen);
	printf("%ld\t", get_time());
	printf("%d %s", (*philo)->pth_id, status);
	pthread_mutex_unlock(&(*philo)->args->pen);
	return (SUCCESS);
}

//비둘기야 밥먹자 구구구구ㅜㄱ구ㅜ
void	*dinner_time(t_pth **philo)
{
	pthread_mutex_lock(&(*philo)->args->fork[(*philo)->l_fork]);
	timestamp(philo, "has taken a fork\n");
	pthread_mutex_lock((*philo)->r_fork);
	timestamp(philo, "has taken a fork\n");
	usleep(1000 * (*philo)->args->time_to_eat);
	sleep_time(philo);
	think_time(philo);
}

void	sleep_time(t_pth **philo)
{

}

void	think_time(t_pth **philo)
{

}

void	monitor(t_all *args, t_pth **philo)
{

}
