/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/23 21:05:05 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

#include <stdio.h>
int	main(int argc __attribute__((unused)), char *argv[])
{
	t_map	*ber;

	ber = (t_map *)malloc(sizeof(t_map));
	map_par(&ber, argv[1]); // 메모리 누수 오져요~
	int	i = 0, j = 0;
	while (ber->map[i++])
		j++;
	for (int i = 0; i < j; i++)
		printf("%s\n", ber->map[i]);
	printf("check_ber : %d\n", check_ber(argv[1]));
	printf("check_rect : %d\n", check_rect(ber));
	printf("check_wall : %d\n", check_wall(ber));
	printf("check_factors : %d\n", check_factors(ber));
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

