/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:48:26 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/16 21:47:44 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_thread(t_arg *args, t_pth *philo);
int		start_philo(t_arg *args, t_pth *philo);
int		main(int argc, char *argv[]);

void	free_thread(t_arg *args, t_pth *philo)
{
	int	i;

	i = 0;
	while (i < args->number_of_philosophers)
		pthread_mutex_destroy(&(args->fork[i++]));
	pthread_mutex_destroy(&args->pen);
	pthread_mutex_destroy(&philo->m_last_eat);
	pthread_mutex_destroy(&args->m_dead);
	pthread_mutex_destroy(&args->m_count_philo_ate);
	pthread_mutex_destroy(&philo->m_last_eat);
	free(philo);
	free(args->fork);
}

int	start_philo(t_arg *args, t_pth *philo)
{
	int			i;

	i = 0;
	while (i < args->number_of_philosophers)
	{
		philo[i].last_eat = get_time();
		if (pthread_create(&(philo[i].pth), NULL, routine, (&philo[i])))
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

int	main(int argc, char *argv[])
{
	t_arg	args;
	t_pth	*philo;

	if (!(argc == 5 || argc == 6))
		return (printf("Arg error\n"));
	if (init_args(&args, argv))
		return (ft_error("args init error\n"));
	if (init_forks(&args))
		return (ft_error("forks init error\n"));
	if (init_philo(&args, &philo))
		return (ft_error("philo init error\n"));
	if (start_philo(&args, philo))
		return (ERROR);
	return (SUCCESS);
}
