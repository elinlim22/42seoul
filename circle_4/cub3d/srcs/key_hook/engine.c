/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:31:48 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/22 20:51:46 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_set(int engine, enum e_mask mask)
{
	return ((engine & mask) != 0);
}

int	get_moveway(int r1, int r2)
{
	return (r1 - r2);
}

void	get_engine(t_mlx *cub3d)
{
	double		dx;
	double		dy;
	const int	move_vertical = get_moveway(is_set(cub3d->engine, MASK_W),
			is_set(cub3d->engine, MASK_S));
	const int	move_horizon = get_moveway(is_set(cub3d->engine, MASK_A),
			is_set(cub3d->engine, MASK_D));
	const int	move_rotate = get_moveway(is_set(cub3d->engine, MASK_L),
			is_set(cub3d->engine, MASK_R));

	dx = cub3d->cam.dir_x / sqrtf(powf(cub3d->cam.dir_x, 2)
			+ powf(cub3d->cam.dir_y, 2));
	dy = cub3d->cam.dir_y / sqrtf(powf(cub3d->cam.dir_x, 2)
			+ powf(cub3d->cam.dir_y, 2));
	if (move_vertical > 0)
		move_forward(&cub3d, dx, dy);
	else if (move_vertical < 0)
		move_back(&cub3d, -dx, -dy);
	if (move_horizon > 0)
		move_left(&cub3d, dy, -dx);
	else if (move_horizon < 0)
		move_right(&cub3d, -dy, dx);
	if (move_rotate > 0)
		rotate_left(&cub3d);
	else if (move_rotate < 0)
		rotate_right(&cub3d);
}
