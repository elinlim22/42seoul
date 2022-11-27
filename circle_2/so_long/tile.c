/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:01:14 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/28 00:33:56 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_tile *tile, void *mlx);
int		count_coll(t_map *ber, char c);
void	draw_map(t_game *game);
void	put_image(t_game *game, char c, int i, int j);

void	img_init(t_tile *tile, void *mlx)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	tile->space = mlx_xpm_file_to_image(mlx, "./xpm/free space.xpm", &w, &h);
	tile->wall = mlx_xpm_file_to_image(mlx, "./xpm/wall.xpm", &w, &h);
	tile->star = mlx_xpm_file_to_image(mlx, "./xpm/star.xpm", &w, &h);
	tile->exit = mlx_xpm_file_to_image(mlx, "./xpm/exit.xpm", &w, &h);
	tile->rocket = mlx_xpm_file_to_image(mlx, "./xpm/up.xpm", &w, &h);
}

int	count_coll(t_map *ber, char c)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (ber->map[i])
	{
		j = 0;
		while (ber->map[i][j])
		{
			if (ber->map[i][j] == c)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->ber->map[i])
	{
		j = 0;
		while (game->ber->map[i][j])
		{
			put_image(game, game->ber->map[i][j], 64 * i, 64 * j);
			j++;
		}
		i++;
	}
}

void	put_image(t_game *game, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->tile.wall, j, i);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->tile.space, j, i);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->tile.star, j, i);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->tile.exit, j, i);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->tile.rocket, j, i);
	else
	{
		mlx_destroy_window(game->mlx, game->win);
		err_msg("wrong factor detected");
	}
}
