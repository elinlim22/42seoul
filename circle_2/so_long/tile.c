/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:01:14 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/26 21:34:51 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_tile *tile, void *mlx);
void	draw_map(t_map *ber, t_game *game, t_tile *tile);

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
	tile->rocket = mlx_xpm_file_to_image(mlx, "./xpm/rocket.xpm", &w, &h);
}

void	draw_map(t_map *ber, t_game *game, t_tile *tile)
{
	int	i;
	int	j;

	i = 0;
	while (ber->map[i])
	{
		j = 0;
		while (ber->map[i][j])
		{
			if (ber->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, tile->wall, 64 * j, 64 * i);
			else if (ber->map[i][j] == '0' || ber->map[i][j] == 'G')
				mlx_put_image_to_window(game->mlx, game->win, tile->space, 64 * j, 64 * i);
			else if (ber->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, tile->star, 64 * j, 64 * i);
			else if (ber->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, tile->exit, 64 * j, 64 * i);
			else
				mlx_put_image_to_window(game->mlx, game->win, tile->rocket, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}
