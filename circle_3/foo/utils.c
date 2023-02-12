/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:15:38 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/12 21:51:54 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		smart_timer(int time);
int			ft_atoi(const char *str);
int			ft_error(char *msg);
long long	get_time(void);
int			timestamp(t_pth *philo, char *status);

void	smart_timer(int time)
{
	long long	start;
	long long	now;

	now = 0;
	start = get_time();
	while ((now - start) <= (long long)time)
	{
		now = get_time();
		usleep(100);
	}
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

int	ft_error(char *msg)
{
	printf("%s", msg);
	return (ERROR);
}

long long	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	timestamp(t_pth *philo, char *status)
{
	pthread_mutex_lock(&(philo->arg->pen));
	printf("%lld\t", get_time() - philo->arg->start);
	printf("%d %s\n", philo->pth_id, status);
	pthread_mutex_unlock(&(philo->arg->pen));
	return (SUCCESS);
}
