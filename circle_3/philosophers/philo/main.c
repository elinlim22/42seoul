/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 01:36:48 by hyeslim           #+#    #+#             */
/*   Updated: 2023/01/30 17:28:44 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*printer(void *i)
{
	if (!i)
		printf("2 success\n");
	else
	{
		usleep(1000 * 1000);
		printf("1 success\n");
	}
	return (NULL);
}

int	main(int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
	t_pth	p1;
	void	*i = NULL;
	void	*j = &p1;

	p1.pth_id = pthread_create(p1.philo, NULL, printer, j);
	printer(i);
	usleep(1000 * 1000 * 5);
	// p2.pth_id = pthread_create(p2.philo, NULL, printer, i);
	if (p1.pth_id < 0)
		printf("fail\n");
	return (0);
}
