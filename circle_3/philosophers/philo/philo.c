/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:35:41 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/01 22:06:08 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_philos(t_all *args, t_pth **philo)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		if (pthread_create((*philo)[i].pth, NULL, dinner_time, philo))
		{
			ft_error("Pthread create error\n");
			return ;
		}
		i++;
	}
	monitor(args, philo);
}

//출력 모듈
void	timestamp(void)
{

}

//비둘기야 밥먹자 구구구구ㅜㄱ구ㅜ
void	*dinner_time(t_pth **philo)
{
	// pthread_mutex_lock();

}

void	monitor(t_all *args, t_pth **philo)
{

}
