/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:03:37 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/17 19:47:32 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_draw(t_mlx *cub3d, t_draw *draw)
{
	if (cub3d->ray.hit_side == 0)
		cub3d->ray.perpdist = (cub3d->ray.map_x - cub3d->cam.pos_x
				+ (1 - cub3d->ray.step_x) / 2) / cub3d->ray.raydir_x;
	if (cub3d->ray.hit_side == 1)
		cub3d->ray.perpdist = (cub3d->ray.map_y - cub3d->cam.pos_y
				+ (1 - cub3d->ray.step_y) / 2) / cub3d->ray.raydir_y;
	if (cub3d->ray.perpdist == 0)
		draw->line_height = HEIGHT;
	else
		draw->line_height = (int)(HEIGHT / cub3d->ray.perpdist);
	draw->draw_start = -(draw->line_height) / 2 + HEIGHT / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + HEIGHT / 2;
	if (draw->draw_end >= HEIGHT)
		draw->draw_end = HEIGHT - 1;
}

t_ray	*init_step(t_mlx *cub3d, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->fdist_x = (cub3d->cam.pos_x - ray->map_x) * ray->ndist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->fdist_x = (ray->map_x + 1 - cub3d->cam.pos_x) * ray->ndist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->fdist_y = (cub3d->cam.pos_y - ray->map_y) * ray->ndist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->fdist_y = (ray->map_y + 1 - cub3d->cam.pos_y) * ray->ndist_y;
	}
	return (ray);
}

void	init_ray(t_mlx *cub3d, t_ray *ray, int x)
{
	ray->cam_x = 2 * x / (double)WIDTH - 1;
	ray->raydir_x = cub3d->cam.dir_x + cub3d->cam.plane_x * ray->cam_x;
	ray->raydir_y = cub3d->cam.dir_y + cub3d->cam.plane_y * ray->cam_x;
	ray->map_x = (int)cub3d->cam.pos_x;
	ray->map_y = (int)cub3d->cam.pos_y;
	if (!ray->raydir_y)
		ray->ndist_x = 0;
	else
	{
		if (!ray->raydir_x)
			ray->ndist_x = 1;
		else
			ray->ndist_x = fabs(1 / ray->raydir_x);
	}
	if (!ray->raydir_x)
		ray->ndist_y = 0;
	else
	{
		if (!ray->raydir_y)
			ray->ndist_y = 1;
		else
			ray->ndist_y = fabs(1 / ray->raydir_y);
	}
	ray = init_step(cub3d, ray);
}
