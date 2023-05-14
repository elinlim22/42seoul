/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:24:22 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/14 14:18:13 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_ret(t_mlx **cub3d)
{
	int	ret;

	ret = 8;
	while (ret > 0)
	{
		if ((*cub3d)->arg->x_size * ret <= WIDTH / 3
			&& (*cub3d)->arg->y_size * ret <= HEIGHT / 3)
		{
			(*cub3d)->mini_ret = ret;
			return ;
		}
		ret--;
	}
	game_exit(*cub3d, EXIT_FAILURE, "Map is too big!");
}

int	*get_texture(t_mlx *cub3d, char *path, t_data *img, int index)
{
	int	x;
	int	y;
	int	*result;

	img->img = mlx_xpm_file_to_image(cub3d->mlx_ptr, path,
			&img->img_w, &img->img_h);
	if (!(img->img))
		game_exit(cub3d, EXIT_FAILURE, "Texture init error!");
	cub3d->tex[index].width = img->img_w;
	cub3d->tex[index].height = img->img_h;
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_size, &img->endian);
	result = malloc(sizeof(int) * img->img_w * img->img_h);
	if (!result)
		game_exit(cub3d, EXIT_FAILURE, "Malloc error!");
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			result[img->img_w * y + x] = img->addr[img->img_w * y + x];
	}
	mlx_destroy_image(cub3d->mlx_ptr, img->img);
	return (result);
}

void	load_texture(t_mlx **cub3d)
{
	t_data	img;

	(*cub3d)->tex = malloc(sizeof(t_tex) * 7);
	(*cub3d)->tex = bzero_texture(*cub3d);
	if (!(*cub3d)->tex)
		game_exit(*cub3d, EXIT_FAILURE, "Malloc error!");
	(*cub3d)->tex[0].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.no, &img, 0);
	(*cub3d)->tex[1].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.so, &img, 1);
	(*cub3d)->tex[2].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.we, &img, 2);
	(*cub3d)->tex[3].texture
		= get_texture(*cub3d, (*cub3d)->arg->root.ea, &img, 3);
	if ((*cub3d)->arg->root.s1)
		(*cub3d)->tex[4].texture
			= get_texture(*cub3d, (*cub3d)->arg->root.s1, &img, 4);
	if ((*cub3d)->arg->root.s2)
		(*cub3d)->tex[5].texture
			= get_texture(*cub3d, (*cub3d)->arg->root.s2, &img, 5);
	if ((*cub3d)->arg->root.door)
		(*cub3d)->tex[6].texture
			= get_texture(*cub3d, (*cub3d)->arg->root.door, &img, 6);
}

void	game_exit(t_mlx *cub3d, int flag, char *string)
{
	if (cub3d && cub3d->img.img)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->img.img);
	if (cub3d && cub3d->win_ptr)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->win_ptr);
	if (cub3d && cub3d->mlx_ptr)
		free(cub3d->mlx_ptr);
	if (cub3d)
	{
		free_all(cub3d->arg);
		if (cub3d->sprite)
			free(cub3d->sprite);
		if (cub3d->tex)
			free_tex(cub3d);
		free(cub3d);
	}
	if (flag)
	{
		printf("%s\n", string);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%s\n", string);
		exit(EXIT_SUCCESS);
	}
}

t_mlx	*game_init(t_mlx *cub3d, t_arg *arg, char *name)
{
	cub3d = malloc(sizeof(t_mlx));
	cub3d->arg = arg;
	if (!cub3d)
		game_exit(cub3d, EXIT_FAILURE, "Malloc error!");
	cub3d->mlx_ptr = mlx_init();
	if (!cub3d->mlx_ptr)
		game_exit(cub3d, EXIT_FAILURE, "Mlx_ptr error!");
	cub3d->win_ptr = mlx_new_window(cub3d->mlx_ptr, WIDTH, HEIGHT, name);
	if (!cub3d->win_ptr)
		game_exit(cub3d, EXIT_FAILURE, "Win_prt error!");
	cub3d->mouse = -1;
	cub3d->mouse_x = 0;
	cub3d->mouse_y = 0;
	cub3d->door = false;
	cub3d->sprite = malloc_sprite(cub3d);
	cub3d->engine = 0;
	sprite_init(&cub3d);
	cub3d->img.img = mlx_new_image(cub3d->mlx_ptr, WIDTH, HEIGHT);
	cub3d->img.addr = (int *)mlx_get_data_addr(cub3d->img.img, \
			&cub3d->img.bits_per_pixel, &cub3d->img.line_size, \
			&cub3d->img.endian);
	load_texture(&cub3d);
	get_ret(&cub3d);
	return (cub3d);
}
