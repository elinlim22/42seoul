/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:24:21 by hyeslim           #+#    #+#             */
/*   Updated: 2023/01/30 17:06:46 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> //pthread_detach, pthread_join,
//						pthread_mutex_init, pthread_mutex_destroy,
//						pthread_mutex_lock, pthread_mutex_unlock
# include <stdlib.h> //malloc, free
# include <stdio.h> //printf
# include <string.h> //memset
# include <sys/time.h> //gettimeofday
# include <unistd.h> //write, usleep

typedef struct s_all
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}				t_all;

typedef struct s_pth
{
	pthread_t	*philo;
	int			pth_id;
}				t_pth;
#endif
