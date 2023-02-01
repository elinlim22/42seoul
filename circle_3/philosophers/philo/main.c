/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:36:48 by hyeslim           #+#    #+#             */
/*   Updated: 2023/02/01 21:28:15 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_all	args;
	t_pth	*philo;

	if (argc != 5 || argc != 6)
		return (ft_error("Wrong arguments\n"));
	if (init_args(&args, argv))
		return (ft_error("Args init error\n"));
	if (init_philo(&args, &philo))
		return (ft_error("Philos init error\n"));
	if (init_forks(&args, &philo))
		return (ft_error("Forks init error\n"));
	start_philos(&args, &philo);
	free(philo);
	return (SUCCESS);
}

// void	*printer(void *i)
// {
// 	if (!i)
// 		printf("2 success\n");
// 	else
// 	{
// 		usleep(1000 * 1000);
// 		printf("1 success\n");
// 	}
// 	return (NULL);
// }

// int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
// {
// 	t_pth	p1;
// 	void	*i = NULL;
// 	void	*j = &p1;

// 	p1.philo_id = pthread_create(p1.philo, NULL, printer, j);
// 	printer(i);
// 	usleep(1000 * 1000 * 5);
// 	if (p1.philo_id < 0)
// 		printf("fail\n");
// 	return (0);
// }
