/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:15:38 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/16 23:46:34 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		smart_timer(int time);
int			ft_atoi(const char *str);
long long	get_time(void);
int			timestamp(t_pth *philo, char *status);

void	smart_timer(int time)
{
	long long	target_time;

	target_time = get_time() + (long long)time;
	while (target_time > get_time())
		usleep(500);
}

int	ft_atoi(const char *str)
{
	long long	n;
	int			i;

	i = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n *= 10;
		n += *str - '0';
		str++;
	}
	n *= i;
	return ((int)n);
}

long long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	timestamp(t_pth *philo, char *status)
{
	pthread_mutex_lock(&philo->arg->m_dead);
	if (!philo->arg->dead)
	{
		pthread_mutex_lock(&(philo->arg->pen));
		printf("%lld\t", get_time() - philo->arg->start);
		if (!status)
			printf("Everyone has done eating\n");
		else
			printf("%d %s\n", philo->pth_id, status);
		pthread_mutex_unlock(&(philo->arg->pen));
	}
	pthread_mutex_unlock(&philo->arg->m_dead);
	return (SUCCESS);
}
