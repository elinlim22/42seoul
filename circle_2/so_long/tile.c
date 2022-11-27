/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:01:14 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/27 17:28:03 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_tile *tile, void *mlx);
void	draw_map(t_game *game);

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
			if (game->ber->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->tile.wall, 64 * j, 64 * i);
			else if (game->ber->map[i][j] == '0' || game->ber->map[i][j] == 'G') // G 옵션 삭제
				mlx_put_image_to_window(game->mlx, game->win, game->tile.space, 64 * j, 64 * i);
			else if (game->ber->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->tile.star, 64 * j, 64 * i);
			else if (game->ber->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->tile.exit, 64 * j, 64 * i);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->tile.rocket, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}
