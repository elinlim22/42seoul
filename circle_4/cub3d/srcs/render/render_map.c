/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:07:40 by youngmch          #+#    #+#             */
/*   Updated: 2023/03/22 21:12:07 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	draw_background(t_mlx *cub3d)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			my_pixel_put(&(cub3d->img), x, y, cub3d->arg->ceiling_rgb);
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			my_pixel_put(&(cub3d->img), x, y, cub3d->arg->floor_rgb);
	}
}

void	init_pixel(t_mlx *cub3d, t_draw draw, t_tex tex, t_pixel *pixel)
{
	if (cub3d->ray.hit_side == 0)
		pixel->wall_x = cub3d->cam.pos_y + cub3d->ray.perpdist
			* cub3d->ray.raydir_y;
	else
		pixel->wall_x = cub3d->cam.pos_x + cub3d->ray.perpdist
			* cub3d->ray.raydir_x;
	pixel->wall_x -= floor(pixel->wall_x);
	pixel->tex_x = (int)(pixel->wall_x * (double) tex.width);
	if (cub3d->ray.hit_side == 0 && cub3d->ray.raydir_x < 0)
		pixel->tex_x = tex.width - pixel->tex_x - 1;
	if (cub3d->ray.hit_side == 1 && cub3d->ray.raydir_y > 0)
		pixel->tex_x = tex.width - pixel->tex_x - 1;
	pixel->step_tex = tex.height / draw.line_height;
	pixel->tex_pos = (draw.draw_start - HEIGHT / 2 + draw.line_height / 2)
		* pixel->step_tex;
}

void	draw_texture(t_mlx *cub3d, t_draw draw, t_tex tex, int x)
{
	int		y;
	int		color;
	t_pixel	pixel;

	init_pixel(cub3d, draw, tex, &pixel);
	y = draw.draw_start - 1;
	while (++y < draw.draw_end)
	{
		pixel.tex_y = (int)pixel.tex_pos & ((int)tex.height - 1);
		pixel.tex_pos += pixel.step_tex;
		color = tex.texture[(int)tex.height * pixel.tex_y + pixel.tex_x];
		my_pixel_put(&(cub3d->img), x, y, color);
	}
}

void	draw_map(t_mlx *cub3d, t_ray *ray, int x, int flag)
{
	t_draw	draw;

	init_draw(cub3d, &draw);
	if (flag == DOOR_C)
		draw_texture(cub3d, draw, cub3d->tex[6], x);
	else if (ray->hit_side == 1 && ray->raydir_y < 0)
		draw_texture(cub3d, draw, cub3d->tex[0], x);
	else if (ray->hit_side == 1 && ray->raydir_y >= 0)
		draw_texture(cub3d, draw, cub3d->tex[1], x);
	else if (ray->hit_side == 0 && ray->raydir_x < 0)
		draw_texture(cub3d, draw, cub3d->tex[2], x);
	else if (ray->hit_side == 0 && ray->raydir_x >= 0)
		draw_texture(cub3d, draw, cub3d->tex[3], x);
}

void	render_map(t_mlx *cub3d)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		init_ray(cub3d, &(cub3d->ray), x);
		if (where_hit(cub3d, &(cub3d->ray)) == 1)
			draw_map(cub3d, &(cub3d->ray), x, 1);
		else
			draw_map(cub3d, &(cub3d->ray), x, DOOR_C);
		cub3d->zbuffer[x] = cub3d->ray.perpdist;
	}
	if (cub3d->sprite_num)
		draw_sprites(cub3d, change_sprite(cub3d->tex));
	draw_minimap(cub3d);
}
