/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:49:04 by hyeslim           #+#    #+#             */
/*   Updated: 2023/03/07 17:24:08 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_arg	args;
	t_prs	*philo;

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
