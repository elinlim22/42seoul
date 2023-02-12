/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:24:21 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/12 18:00:25 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define ERROR 1

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
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	pen;
	uint64_t		start;
}				t_all;

typedef struct s_pth
{
	pthread_t	pth;
	int			pth_id;
	int			l_fork;
	int			r_fork;
	int			count_eat;
	int			max_eat;
	t_all		*args;
	uint64_t	last_eat;
}				t_pth;

// utils.c
int			ft_atoi(const char *str);
int			ft_error(char *msg);
uint64_t	get_time(void);

// init.c
int			init_philo(t_all *args, t_pth **philo);
int			init_args(t_all *args, char *argv[]);
int			check_args(t_all *args);
int			init_forks(t_all *args);

// philo.c
void		start_philos(t_all *args, t_pth **philo);
int			timestamp(t_pth *philo, char *status);
void		monitor(t_pth **philo, t_all *args);
void		*monitor_limit(void *philo_v);

// works.c
void		*dinner_time(void *philo_v);
void		routine(t_all *args, t_pth *philo);
// void		sleep_time(t_pth **philo);

// void	free_philos(t_all *args, t_pth *philo);
#endif
