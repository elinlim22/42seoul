/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/27 17:43:53 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

void	err_msg(char *msg);
int		exit_game(t_game *game);
int		key(int k, t_game *game);
void	locate_p(t_game *game);


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
		mv_w(game);
	if (k == K_A)
		mv_a(game);
	if (k == K_S)
		mv_s(game);
	if (k == K_D)
		mv_d(game);
	return (0);
}

void	locate_p(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->ber->map[i])
	{
		j = 0;
		while (game->ber->map[i][j])
		{
			if (game->ber->map[i][j] == 'P')
			{
				game->x = j;
				game->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->ber->map[i])
	{
		if (ft_strchr(game->ber->map[i++], 'C'))
		{
			ft_printf("you lose\n");
			break ;
		}
	}
	mlx_destroy_window(game->mlx, game->win);
	ft_printf("move : %d\n", game->count);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_map	*ber;
	t_game	game;

	if (argc != 2)
		err_msg("too many arguments");
	ber = (t_map *)malloc(sizeof(t_map));
	map_par(&ber, argv[1]); // 메모리 누수 오져요~
	game.ber = ber;

	/* show xpm file */
	// int	i = 0, j = 0;
	// while (ber->map[i++])
	// 	j++;
	// for (int i = 0; i < j; i++)
	// 	ft_printf("%s\n", ber->map[i]);


	if (check_ber(argv[1]) && check_rect(ber) && check_wall(ber) && check_factors(ber))
	{
		t_tile	tile;
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, 64 * game.ber->width, 64 * game.ber->height, "Hyeslim's rocket");
		game.count = 0;
		locate_p(&game);
		img_init(&tile, game.mlx);
		game.tile = tile;
		draw_map(&game);

		// hook 넣을 자리
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key, &game);
		mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);

		mlx_loop(game.mlx);
	}
	exit (0);
}

// starting position 이미지 바꾸기 : 로켓이 안보임,, 배경도 회색으로 좀 바꾸기
