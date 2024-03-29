/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:04:58 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/28 00:15:56 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key(int k, t_game *game);
void	mv_w(t_game *game);
void	mv_a(t_game *game);
void	mv_s(t_game *game);
void	mv_d(t_game *game);

int	key(int k, t_game *game)
{
	if (k == K_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
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

void	mv_w(t_game *game)
{
	int	temp;
	int	fix;

	temp = game->y - 1;
	fix = 64;
	if (temp < 0)
		return ;
	if (game->ber->map[temp][game->x] != '1')
	{
		game->count++;
		game->ber->map[game->y][game->x] = '0';
		if (game->ber->map[temp][game->x] != 'E')
			game->ber->map[temp][game->x] = 'P';
		else
		{
			game->ber->map[temp][game->x] = 'P';
			exit_game(game);
		}
		game->y = temp;
	}
	game->tile.rocket = \
		mlx_xpm_file_to_image(game->mlx, "./xpm/up.xpm", &fix, &fix);
	draw_map(game);
}

void	mv_a(t_game *game)
{
	int	temp;
	int	fix;

	temp = game->x - 1;
	fix = 64;
	if (temp < 0)
		return ;
	if (game->ber->map[game->y][temp] != '1')
	{
		game->count++;
		game->ber->map[game->y][game->x] = '0';
		if (game->ber->map[game->y][temp] != 'E')
			game->ber->map[game->y][temp] = 'P';
		else
		{
			game->ber->map[game->y][temp] = 'P';
			exit_game(game);
		}
		game->x = temp;
	}
	game->tile.rocket = \
		mlx_xpm_file_to_image(game->mlx, "./xpm/left.xpm", &fix, &fix);
	draw_map(game);
}

void	mv_s(t_game *game)
{
	int	temp;
	int	fix;

	temp = game->y + 1;
	fix = 64;
	if (temp > game->ber->height)
		return ;
	if (game->ber->map[temp][game->x] != '1')
	{
		game->count++;
		game->ber->map[game->y][game->x] = '0';
		if (game->ber->map[temp][game->x] != 'E')
			game->ber->map[temp][game->x] = 'P';
		else
		{
			game->ber->map[temp][game->x] = 'P';
			exit_game(game);
		}
		game->y = temp;
	}
	game->tile.rocket = \
		mlx_xpm_file_to_image(game->mlx, "./xpm/down.xpm", &fix, &fix);
	draw_map(game);
}

void	mv_d(t_game *game)
{
	int	temp;
	int	fix;

	temp = game->x + 1;
	fix = 64;
	if (temp > game->ber->width)
		return ;
	if (game->ber->map[game->y][temp] != '1')
	{
		game->count++;
		game->ber->map[game->y][game->x] = '0';
		if (game->ber->map[game->y][temp] != 'E')
			game->ber->map[game->y][temp] = 'P';
		else
		{
			game->ber->map[game->y][temp] = 'P';
			exit_game(game);
		}
		game->x = temp;
	}
	game->tile.rocket = \
		mlx_xpm_file_to_image(game->mlx, "./xpm/right.xpm", &fix, &fix);
	draw_map(game);
}
