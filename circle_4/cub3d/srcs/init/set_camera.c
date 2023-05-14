/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:09:00 by youngmin          #+#    #+#             */
/*   Updated: 2023/03/22 21:05:03 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_plane(t_cam *cam, int val)
{
	if (val == NORTH)
	{
		cam->plane_x = 0.66;
		cam->plane_y = 0.0;
	}
	else if (val == SOUTH)
	{
		cam->plane_x = -0.66;
		cam->plane_y = 0.0;
	}
	else if (val == WEST)
	{
		cam->plane_x = 0.0;
		cam->plane_y = -0.66;
	}
	else if (val == EAST)
	{
		cam->plane_x = 0.0;
		cam->plane_y = 0.66;
	}
}

void	set_dir(t_cam *cam, int val)
{
	if (val == NORTH)
	{
		cam->dir_x = 0.0;
		cam->dir_y = -1.0;
	}
	else if (val == SOUTH)
	{
		cam->dir_x = 0.0;
		cam->dir_y = 1.0;
	}
	else if (val == WEST)
	{
		cam->dir_x = -1.0;
		cam->dir_y = 0.0;
	}
	else if (val == EAST)
	{
		cam->dir_x = 1.0;
		cam->dir_y = 0.0;
	}
}

void	set_cam(t_mlx **cub3d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*cub3d)->arg->y_size)
	{
		j = -1;
		while (++j < (*cub3d)->arg->x_size)
		{
			if ((*cub3d)->arg->map[i][j].val >= NORTH
				&& (*cub3d)->arg->map[i][j].val <= EAST)
			{
				(*cub3d)->cam.pos_x = (double)j;
				(*cub3d)->cam.pos_y = (double)i;
				set_dir(&((*cub3d)->cam), (*cub3d)->arg->map[i][j].val);
				set_plane(&((*cub3d)->cam), (*cub3d)->arg->map[i][j].val);
				(*cub3d)->arg->map[i][j].val = 0;
				break ;
			}
		}
	}
	(*cub3d)->cam.move_speed = 0.05;
	(*cub3d)->cam.rot_speed = 0.025;
}
