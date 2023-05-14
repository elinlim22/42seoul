/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:15:06 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/22 20:52:14 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rotate_right(t_mlx **cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = (*cub3d)->cam.dir_x;
	(*cub3d)->cam.dir_x = (*cub3d)->cam.dir_x * cos((*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.dir_y * sin((*cub3d)->cam.rot_speed);
	(*cub3d)->cam.dir_y = old_dir_x * sin((*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.dir_y * cos((*cub3d)->cam.rot_speed);
	old_plane_x = (*cub3d)->cam.plane_x;
	(*cub3d)->cam.plane_x = old_plane_x * cos((*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.plane_y * sin((*cub3d)->cam.rot_speed);
	(*cub3d)->cam.plane_y = old_plane_x * sin((*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.plane_y * cos((*cub3d)->cam.rot_speed);
}

void	rotate_left(t_mlx **cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = (*cub3d)->cam.dir_x;
	(*cub3d)->cam.dir_x = (*cub3d)->cam.dir_x * cos(-(*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.dir_y * sin(-(*cub3d)->cam.rot_speed);
	(*cub3d)->cam.dir_y = old_dir_x * sin(-(*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.dir_y * cos(-(*cub3d)->cam.rot_speed);
	old_plane_x = (*cub3d)->cam.plane_x;
	(*cub3d)->cam.plane_x = old_plane_x * cos(-(*cub3d)->cam.rot_speed)
		- (*cub3d)->cam.plane_y * sin(-(*cub3d)->cam.rot_speed);
	(*cub3d)->cam.plane_y = old_plane_x * sin(-(*cub3d)->cam.rot_speed)
		+ (*cub3d)->cam.plane_y * cos(-(*cub3d)->cam.rot_speed);
}
