/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:53:25 by youngmin          #+#    #+#             */
/*   Updated: 2023/03/22 21:58:18 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	click_exit(t_mlx *cub3d)
{
	game_exit(cub3d, EXIT_SUCCESS, "Thanks!\nBy hyeslim & youngmch");
	return (0);
}

void	mouse_hook(t_mlx **cub3d)
{
	(*cub3d)->mouse *= -1;
	if ((*cub3d)->mouse == 1)
	{
		mlx_mouse_hide();
		mlx_mouse_move((*cub3d)->win_ptr, WIDTH / 2, HEIGHT / 2);
		mlx_mouse_get_pos((*cub3d)->win_ptr, &((*cub3d)->mouse_x),
			&((*cub3d)->mouse_y));
	}
	else
		mlx_mouse_show();
}

int	key_hook(int keycode, t_mlx *cub3d)
{
	if (keycode == KEY_ESC)
		game_exit(cub3d, EXIT_SUCCESS, "Thanks!\nBy hyeslim & youngmch");
	if (keycode == KEY_W)
		cub3d->engine |= MASK_W;
	if (keycode == KEY_S)
		cub3d->engine |= MASK_S;
	if (keycode == KEY_A)
		cub3d->engine |= MASK_A;
	if (keycode == KEY_D)
		cub3d->engine |= MASK_D;
	if (keycode == KEY_LEFT)
		cub3d->engine |= MASK_L;
	if (keycode == KEY_RIGHT)
		cub3d->engine |= MASK_R;
	if (keycode == KEY_DOOR)
		door_control(cub3d);
	if (keycode == KEY_ONE)
		mouse_hook(&cub3d);
	return (0);
}

int	key_release(int keycode, t_mlx *cub3d)
{
	if (keycode == KEY_W)
		cub3d->engine &= ~MASK_W;
	if (keycode == KEY_S)
		cub3d->engine &= ~MASK_S;
	if (keycode == KEY_A)
		cub3d->engine &= ~MASK_A;
	if (keycode == KEY_D)
		cub3d->engine &= ~MASK_D;
	if (keycode == KEY_LEFT)
		cub3d->engine &= ~MASK_L;
	if (keycode == KEY_RIGHT)
		cub3d->engine &= ~MASK_R;
	return (0);
}

void	key_hook_event(t_mlx *cub3d)
{
	draw_background(cub3d);
	render_map(cub3d);
	mlx_put_image_to_window(cub3d->mlx_ptr, cub3d->win_ptr,
		cub3d->img.img, 0, 0);
	mlx_hook(cub3d->win_ptr, KEY_PRESS, 0, key_hook, cub3d);
	mlx_hook(cub3d->win_ptr, KEY_RELEASE, 0, key_release, cub3d);
	mlx_hook(cub3d->win_ptr, KEY_EXIT, 0, click_exit, cub3d);
	mlx_loop_hook(cub3d->mlx_ptr, game_loop, cub3d);
	mlx_loop(cub3d->mlx_ptr);
}
