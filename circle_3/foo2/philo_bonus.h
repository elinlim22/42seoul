/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:47:51 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/07 17:14:32 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define SUCCESS 0
# define ERROR 1

# include <pthread.h> //pthread_create, pthread_detach, pthread_join
# include <semaphore.h> //sem_open, sem_close,
//						sem_post, sem_wait, sem_unlink
# include <signal.h> //kill
# include <stdlib.h> //malloc, free, exit
# include <stdio.h> //printf
# include <string.h> //memset
# include <sys/time.h> //gettimeofday
# include <unistd.h> //write, usleep, fork

typedef struct s_arg
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_eat;
	sem_t		*fork;
	sem_t		pen;
	long long	start;
}				t_arg;

typedef struct s_prs
{
	int			prs_id;
	int			count_eat;
	pid_t		prs;
	long long	last_eat;
	sem_t		sm_last_eat;
	t_arg		*arg;
}				t_prs;

// init_bonus.c

// philo_bonus.c

// utils_bonus.c

// main_bonus.c

#endif
