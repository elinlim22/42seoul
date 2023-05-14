/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmin <youngmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:55:54 by youngmin          #+#    #+#             */
/*   Updated: 2023/03/17 19:48:47 by youngmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	where_hit(t_mlx *cub3d, t_ray *ray)
{
	while (1)
	{
		if (ray->fdist_x < ray->fdist_y)
		{
			ray->fdist_x += ray->ndist_x;
			ray->map_x += ray->step_x;
			ray->hit_side = 0;
		}
		else
		{
			ray->fdist_y += ray->ndist_y;
			ray->map_y += ray->step_y;
			ray->hit_side = 1;
		}
		if (cub3d->arg->map[ray->map_y][ray->map_x].val == 1
			|| cub3d->arg->map[ray->map_y][ray->map_x].val == DOOR_C)
			return (cub3d->arg->map[ray->map_y][ray->map_x].val);
	}
	return (0);
}
