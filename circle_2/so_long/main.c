/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/28 00:18:39 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

void	err_msg(char *msg);
void	locate_p(t_game *game);
int		exit_game(t_game *game);
void	init_game(t_game *game, t_tile *tile);

void	err_msg(char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit(1);
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
			ft_printf("LOSE : you did not clear the map\n");
			mlx_destroy_window(game->mlx, game->win);
			exit(0);
		}
	}
	mlx_destroy_window(game->mlx, game->win);
	ft_printf("WIN : you cleared the map\n");
	ft_printf("move : %d\n", game->count);
	exit(0);
}

void	init_game(t_game *game, t_tile *tile)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 64 * game->ber->width, \
					64 * game->ber->height, "Hyeslim's rocket");
	game->count = 0;
	img_init(tile, game->mlx);
	game->tile = *tile;
	draw_map(game);
}

int	main(int argc, char *argv[])
{
	t_map	*ber;
	t_game	game;
	t_tile	tile;

	if (argc != 2)
		err_msg("too many arguments");
	ber = (t_map *)malloc(sizeof(t_map));
	map_par(&ber, argv[1]);
	game.ber = ber;
	locate_p(&game);
	game.ber->coll = count_coll(game.ber, 'C');
	if (check_ber(argv[1]) && check_rect(ber) && check_wall(ber) && \
		check_factors(ber) && validity(&game))
	{
		init_game(&game, &tile);
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key, &game);
		mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
		mlx_loop(game.mlx);
	}
	exit (0);
}
