/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:48:22 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/16 21:47:36 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(t_arg *args, t_pth *philo);
void	*routine(void *data);
void	philo_work(t_pth *philo);
void	detector(t_arg *args, t_pth *philo, int flag);
int		breaker(t_pth *philo);

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
				return (detector(args, &philo[i], DEAD));
			pthread_mutex_unlock(&philo[i].m_last_eat);
			pthread_mutex_lock(&args->m_count_philo_ate);
			if (args->count_philo_ate == args->number_of_philosophers)
				return (detector(args, &philo[i], DONE));
			pthread_mutex_unlock(&args->m_count_philo_ate);
			i++;
		}
	}
}

void	detector(t_arg *args, t_pth *philo, int flag)
{
	if (flag == DEAD)
	{
		pthread_mutex_unlock(&philo->m_last_eat);
		timestamp(philo, "died");
		pthread_mutex_lock(&args->m_dead);
		args->dead = 1;
		pthread_mutex_unlock(&args->m_dead);
	}
	if (flag == DONE)
	{
		timestamp(philo, NULL);
		pthread_mutex_unlock(&args->m_count_philo_ate);
	}
}

void	*routine(void *data)
{
	t_pth	*philo;

	philo = (t_pth *)data;
	pthread_mutex_lock(&philo->m_last_eat);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->m_last_eat);
	if (philo->pth_id % 2)
		smart_timer(100);
	while (1)
		if (!breaker(philo))
			break ;
	return ((void *)SUCCESS);
}

int	breaker(t_pth *philo)
{
	pthread_mutex_lock(&philo->arg->m_dead);
	if (philo->arg->dead)
		return (pthread_mutex_unlock(&philo->arg->m_dead));
	pthread_mutex_unlock(&philo->arg->m_dead);
	philo_work(philo);
	if (philo->count_eat == philo->arg->number_of_times_eat)
	{
		pthread_mutex_lock(&philo->arg->m_count_philo_ate);
		philo->arg->count_philo_ate++;
		return (pthread_mutex_unlock(&philo->arg->m_count_philo_ate));
	}
	return (1);
}

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
	if (philo->count_eat == philo->arg->number_of_times_eat)
		return ;
	timestamp(philo, "is sleeping");
	smart_timer(philo->arg->time_to_sleep);
	timestamp(philo, "is thinking");
}
