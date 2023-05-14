/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:19:56 by youngmin          #+#    #+#             */
/*   Updated: 2023/03/20 13:49:47 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_player(t_mlx *cub3d, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (++dy < cub3d->mini_ret)
	{
		dx = -1;
		while (++dx < cub3d->mini_ret)
			my_pixel_put(&(cub3d->img), dx + x, dy + y, color);
	}
}

void	draw_square(t_mlx *cub3d, int x, int y, int color)
{
	int	dx;
	int	dy;

	dy = -1;
	while (++dy < cub3d->mini_ret)
	{
		dx = -1;
		while (++dx < cub3d->mini_ret)
			my_pixel_put(&(cub3d->img), dx + x, dy + y, color);
	}
}

void	draw_minimap(t_mlx *cub3d)
{
	int	x;
	int	y;
	int	ret;

	ret = cub3d->mini_ret;
	y = -1;
	while (++y < cub3d->arg->y_size)
	{
		x = -1;
		while (++x < cub3d->arg->x_size)
		{
			if ((int)cub3d->cam.pos_x == x && (int)cub3d->cam.pos_y == y)
				draw_player(cub3d, x * ret, y * ret, 0x6C3BF4);
			else if (cub3d->arg->map[y][x].val == 1)
				draw_square(cub3d, x * ret, y * ret, 0x000000);
			else if (cub3d->arg->map[y][x].val == 0)
				draw_square(cub3d, x * ret, y * ret, 0xAEAEAE);
			else if (cub3d->arg->map[y][x].val == 2)
				draw_player(cub3d, x * ret, y * ret, 0xF72F3A);
			else if (cub3d->arg->map[y][x].val >= DOOR_C)
				draw_player(cub3d, x * ret, y * ret, 0xFFFFFF);
		}
	}
}
