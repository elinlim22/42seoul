/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:24:21 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/06 17:16:34 by hyeslim          ###   ########.fr       */
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

typedef struct s_arg
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_eat;
	pthread_mutex_t	*fork;
	pthread_mutex_t	pen;
	long long		start;
	int				flag;
	int				dead;
	pthread_mutex_t	m_dead;
}				t_arg;

typedef struct s_pth
{
	int				pth_id;
	pthread_t		pth;
	int				count_eat;
	int				max_eat;
	int				l_fork;
	int				r_fork;
	long long		last_eat;
	pthread_mutex_t	m_last_eat;
	t_arg			*arg;
}				t_pth;

// init.c
int			init_args(t_arg *args, char *argv[]);
int			check_args(t_arg *args);
int			init_philo(t_arg *args, t_pth **philo);
int			init_forks(t_arg *args);

// philo.c
int			start_philo(t_arg *args, t_pth *philo);
void		monitor(t_arg *args, t_pth *philo);
void		*routine_limit(void *data);
// void		*routine(void *data);
void		philo_work(t_pth *philo);

// utils.c
void		smart_timer(int time);
int			ft_atoi(const char *str);
int			ft_error(char *msg);
long long	get_time(void);
int			timestamp(t_pth *philo, char *status);

// main.c
void		free_thread(t_arg *arg, t_pth *philo);
/*
















// typedef struct s_all
// {
// 	int				number_of_philosophers;
// 	int				time_to_die;
// 	int				time_to_eat;
// 	int				time_to_sleep;
// 	int				number_of_times_each_philosopher_must_eat;
// 	pthread_mutex_t	*fork;
// 	pthread_mutex_t	pen;
// 	uint64_t		start;
// }				t_all;

// typedef struct s_pth
// {
// 	pthread_t	pth;
// 	int			pth_id;
// 	int			l_fork;
// 	int			r_fork;
// 	int			count_eat;
// 	int			max_eat;
// 	t_all		*args;
// 	uint64_t	last_eat;
// }				t_pth;

// // utils.c
// int			ft_atoi(const char *str);
// int			ft_error(char *msg);
// uint64_t	get_time(void);

// // init.c
// int			init_philo(t_all *args, t_pth **philo);
// int			init_args(t_all *args, char *argv[]);
// int			check_args(t_all *args);
// int			init_forks(t_all *args);

// // philo.c
// void		start_philos(t_all *args, t_pth **philo);
// int			timestamp(t_pth *philo, char *status);
// void		monitor(t_pth **philo, t_all *args);
// void		*monitor_limit(void *philo_v);

// // works.c
// void		*dinner_time(void *philo_v);
// void		routine(t_all *args, t_pth *philo);
// // void		sleep_time(t_pth **philo);

// void	free_philos(t_all *args, t_pth *philo);
#endif
*/
#endif
