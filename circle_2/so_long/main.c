/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/23 21:35:52 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

void	err_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_map	*ber;

	if (argc != 2)
		err_msg("too many arguments");
	ber = (t_map *)malloc(sizeof(t_map));
	map_par(&ber, argv[1]); // 메모리 누수 오져요~
	int	i = 0, j = 0;
	while (ber->map[i++])
		j++;
	for (int i = 0; i < j; i++)
		ft_printf("%s\n", ber->map[i]);
	ft_printf("check_ber : %d\n", check_ber(argv[1]));
	ft_printf("check_rect : %d\n", check_rect(ber));
	ft_printf("check_wall : %d\n", check_wall(ber));
	ft_printf("check_factors : %d\n", check_factors(ber));
	err_msg("test");
	exit(0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

