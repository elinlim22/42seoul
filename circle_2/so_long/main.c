/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/26 22:09:42 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

void	err_msg(char *msg);
int		exit_game(t_game *game);

void	err_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(1);
}

int	key(int k, t_game *game)
{
	if (k == K_ESC)
		exit_game(game);
	if (k == K_W)
		game->y += 64;
	if (k == K_A)
		game->x -= 64;
	if (k == K_S)
		game->y -= 64;
	if (k == K_D)
		game->x += 64;
	return (0);
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_map	*ber;

	if (argc != 2)
		err_msg("too many arguments");
	ber = (t_map *)malloc(sizeof(t_map));
	map_par(&ber, argv[1]); // 메모리 누수 오져요~


	/* show xpm file */
	// int	i = 0, j = 0;
	// while (ber->map[i++])
	// 	j++;
	// for (int i = 0; i < j; i++)
	// 	ft_printf("%s\n", ber->map[i]);


	if (check_ber(argv[1]) && check_rect(ber) && check_wall(ber) && check_factors(ber))
	{
		t_tile	tile;
		t_game	game;
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, 64 * ber->width, 64 * ber->height, "Hyeslim's rocket");
		game.count = 0;
		game.x = 0;
		game.y = 0;
		img_init(&tile, game.mlx);
		draw_map(ber, &game, &tile);

		// hook 넣을 자리
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key, &game);
		mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);

		mlx_loop(game.mlx);
	}
	else
		return (0);
}

// starting position 이미지 바꾸기 : 로켓이 안보임,, 배경도 회색으로 좀 바꾸기
