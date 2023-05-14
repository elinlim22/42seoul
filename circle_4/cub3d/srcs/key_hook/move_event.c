/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:10:29 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/22 20:43:29 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	move_forward(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != 1
		&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != DOOR_C)
		(*cub3d)->cam.pos_x += vec_x;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != 1
			&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != DOOR_C)
		(*cub3d)->cam.pos_y += vec_y;
}

void	move_back(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != 1
		&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != DOOR_C)
		(*cub3d)->cam.pos_x += vec_x;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != 1
			&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != DOOR_C)
		(*cub3d)->cam.pos_y += vec_y;
}

void	move_left(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != 1
		&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != DOOR_C)
		(*cub3d)->cam.pos_x += vec_x;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != 1
			&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != DOOR_C)
		(*cub3d)->cam.pos_y += vec_y;
}

void	move_right(t_mlx **cub3d, double dx, double dy)
{
	double	vec_x;
	double	vec_y;

	vec_x = dx * (*cub3d)->cam.move_speed;
	vec_y = dy * (*cub3d)->cam.move_speed;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != 1
		&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y)][(int)
		((*cub3d)->cam.pos_x + vec_x * 1.1)].val != DOOR_C)
		(*cub3d)->cam.pos_x += vec_x;
	if ((*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != 1
			&& (*cub3d)->arg->map[(int)((*cub3d)->cam.pos_y + vec_y
			* 1.1)][(int)((*cub3d)->cam.pos_x)].val != DOOR_C)
		(*cub3d)->cam.pos_y += vec_y;
}
