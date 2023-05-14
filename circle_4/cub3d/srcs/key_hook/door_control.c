/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:13:54 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/20 15:01:01 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	no_door(t_mlx **cub3d)
{
	int	x;
	int	y;

	x = (*cub3d)->cam.pos_x;
	y = (*cub3d)->cam.pos_y;
	if ((*cub3d)->arg->map[y + 1][x].val == DOOR_C)
		(*cub3d)->arg->map[y + 1][x].val = DOOR_O;
	else if ((*cub3d)->arg->map[y + 1][x].val == DOOR_O)
		(*cub3d)->arg->map[y + 1][x].val = DOOR_C;
	else if ((*cub3d)->arg->map[y + 2][x].val == DOOR_C)
		(*cub3d)->arg->map[y + 2][x].val = DOOR_O;
	else if ((*cub3d)->arg->map[y + 2][x].val == DOOR_O)
		(*cub3d)->arg->map[y + 2][x].val = DOOR_C;
	else
	{
		(*cub3d)->door = false;
		return ;
	}
	(*cub3d)->door = true;
}

void	so_door(t_mlx **cub3d)
{
	int	x;
	int	y;

	x = (*cub3d)->cam.pos_x;
	y = (*cub3d)->cam.pos_y;
	if ((*cub3d)->arg->map[y - 1][x].val == DOOR_C)
		(*cub3d)->arg->map[y - 1][x].val = DOOR_O;
	else if ((*cub3d)->arg->map[y - 1][x].val == DOOR_O)
		(*cub3d)->arg->map[y - 1][x].val = DOOR_C;
	else if ((*cub3d)->arg->map[y - 2][x].val == DOOR_C)
		(*cub3d)->arg->map[y - 2][x].val = DOOR_O;
	else if ((*cub3d)->arg->map[y - 2][x].val == DOOR_O)
		(*cub3d)->arg->map[y - 2][x].val = DOOR_C;
	else
	{
		(*cub3d)->door = false;
		return ;
	}
	(*cub3d)->door = true;
}

void	ea_door(t_mlx **cub3d)
{
	int	x;
	int	y;

	x = (*cub3d)->cam.pos_x;
	y = (*cub3d)->cam.pos_y;
	if ((*cub3d)->arg->map[y][x + 1].val == DOOR_C)
		(*cub3d)->arg->map[y][x + 1].val = DOOR_O;
	else if ((*cub3d)->arg->map[y][x + 1].val == DOOR_O)
		(*cub3d)->arg->map[y][x + 1].val = DOOR_C;
	else if ((*cub3d)->arg->map[y][x + 2].val == DOOR_C)
		(*cub3d)->arg->map[y][x + 2].val = DOOR_O;
	else if ((*cub3d)->arg->map[y][x + 2].val == DOOR_O)
		(*cub3d)->arg->map[y][x + 2].val = DOOR_C;
	else
	{
		(*cub3d)->door = false;
		return ;
	}
	(*cub3d)->door = true;
}

void	we_door(t_mlx **cub3d)
{
	int	x;
	int	y;

	x = (*cub3d)->cam.pos_x;
	y = (*cub3d)->cam.pos_y;
	if ((*cub3d)->arg->map[y][x - 1].val == DOOR_C)
		(*cub3d)->arg->map[y][x - 1].val = DOOR_O;
	else if ((*cub3d)->arg->map[y][x - 1].val == DOOR_O)
		(*cub3d)->arg->map[y][x - 1].val = DOOR_C;
	else if ((*cub3d)->arg->map[y][x - 2].val == DOOR_C)
		(*cub3d)->arg->map[y][x - 2].val = DOOR_O;
	else if ((*cub3d)->arg->map[y][x - 2].val == DOOR_O)
		(*cub3d)->arg->map[y][x - 2].val = DOOR_C;
	else
	{
		(*cub3d)->door = false;
		return ;
	}
	(*cub3d)->door = true;
}

void	door_control(t_mlx *cub3d)
{
	if (cub3d->cam.dir_y > 0.9)
		no_door(&cub3d);
	else if (cub3d->cam.dir_y < -0.9)
		so_door(&cub3d);
	else if (cub3d->cam.dir_x > 0.9)
		ea_door(&cub3d);
	else if (cub3d->cam.dir_x < -0.9)
		we_door(&cub3d);
}
