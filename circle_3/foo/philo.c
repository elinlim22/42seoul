/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:48:22 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/06 17:51:38 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		start_philo(t_arg *args, t_pth *philo);
void	monitor(t_arg *args, t_pth *philo);
void	*routine_limit(void *data);
// void	*routine(void *data);
void	philo_work(t_pth *philo);

int	start_philo(t_arg *args, t_pth *philo)
{
	int			i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		philo[i].last_eat = get_time();
		if (pthread_create(&(philo[i].pth), NULL, routine_limit, (&philo[i])))
			return (ERROR);
		i++;
	}
	monitor(args, philo);
	i = 0;
	while (i < args->number_of_philosophers)
		pthread_join(philo[i++].pth, NULL);
	free_thread(args, philo);
	return (SUCCESS);
}

void	monitor(t_arg *args, t_pth *philo)
{
	long long	now;
	int			i;

	while (1)
	{
		i = 0;
		while (i < args->number_of_philosophers)
		{
			now = get_time();
			pthread_mutex_lock(&philo[i].m_last_eat);
			if (now - philo[i].last_eat >= (long long)(args->time_to_die))
			{
				pthread_mutex_unlock(&philo[i].m_last_eat);
				timestamp(philo, "died");
				pthread_mutex_lock(&args->m_dead);
				args->dead = 1;
				pthread_mutex_unlock(&args->m_dead);
				return ;
			}
			pthread_mutex_unlock(&philo[i].m_last_eat);
			i++;
		}
	}
}

void	*routine_limit(void *data)
{
	t_pth	*philo;

	philo = (t_pth *)data;
	pthread_mutex_lock(&philo->m_last_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->m_last_eat);
	if (philo->pth_id % 2)
		smart_timer(100);
	while (philo->count_eat != philo->arg->number_of_times_eat)
	{
		pthread_mutex_lock(&philo->arg->m_dead);
		if (philo->arg->dead)
		{
			pthread_mutex_unlock(&philo->arg->m_dead);
			break ;
		}
		pthread_mutex_unlock(&philo->arg->m_dead);
		philo_work(philo);
	}
	return ((void *)SUCCESS);
}

// void	*routine(void *data)
// {
// 	t_pth	*philo;

// 	philo = (t_pth *)data;
// 	(*philo).last_eat = get_time();
// 	while (1)
// 		philo_work(philo);
// 	return ((void *)SUCCESS);
// }

void	philo_work(t_pth *philo)
{
	pthread_mutex_lock(&(philo->arg->fork[philo->r_fork]));
	timestamp(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->arg->fork[philo->l_fork]));
	timestamp(philo, "has taken a fork");
	timestamp(philo, "is eating");
	smart_timer(philo->arg->time_to_eat);
	pthread_mutex_lock(&philo->m_last_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->m_last_eat);
	philo->count_eat++;
	pthread_mutex_unlock(&(philo->arg->fork[philo->r_fork]));
	pthread_mutex_unlock(&(philo->arg->fork[philo->l_fork]));
	timestamp(philo, "is sleeping");
	smart_timer(philo->arg->time_to_sleep);
	timestamp(philo, "is thinking");
}
