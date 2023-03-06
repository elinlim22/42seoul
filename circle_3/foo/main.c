/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:48:26 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/06 17:22:30 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_thread(t_arg *arg, t_pth *philo)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philosophers)
		pthread_mutex_destroy(&(arg->fork[i++]));
	pthread_mutex_destroy(&(arg->pen));
	pthread_mutex_destroy(&philo->m_last_eat);
	pthread_mutex_destroy(&arg->m_dead);
	free(philo);
	free(arg->fork);
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
