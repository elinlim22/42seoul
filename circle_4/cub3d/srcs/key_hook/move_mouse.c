/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 22:54:31 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/22 22:00:44 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_mouse(t_mlx *cub3d)
{
	int	x;
	int	y;
	int	dir;
	int	abs_x;

	mlx_mouse_get_pos(cub3d->win_ptr, &x, &y);
	if (x - cub3d->mouse_x < 0)
		dir = 0;
	else
		dir = 1;
	abs_x = abs(x - cub3d->mouse_x);
	if (abs_x >= 1)
	{
		mlx_mouse_move(cub3d->win_ptr, WIDTH / 2, HEIGHT / 2);
		cub3d->cam.rot_speed = 0.02;
		while (abs_x > 0)
		{
			if (!dir)
				rotate_left(&cub3d);
			else
				rotate_right(&cub3d);
			abs_x -= 25;
		}
	}
	cub3d->cam.rot_speed = 0.025;
}
