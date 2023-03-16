/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:24:21 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/16 23:46:26 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define SUCCESS 0
# define ERROR 1
# define DEAD 0
# define DONE 1

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

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
	int				dead;
	int				count_philo_ate;
	pthread_mutex_t	m_count_philo_ate;
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

// main.c
void		free_thread(t_arg *args, t_pth *philo);
int			start_philo(t_arg *args, t_pth *philo);
int			main(int argc, char *argv[]);

// philo.c
void		monitor(t_arg *args, t_pth *philo);
void		*routine(void *data);
void		philo_work(t_pth *philo);
void		detector(t_arg *args, t_pth *philo, int flag);
int			breaker(t_pth *philo);

// utils.c
void		smart_timer(int time);
int			ft_atoi(const char *str);
long long	get_time(void);
int			timestamp(t_pth *philo, char *status);

#endif
