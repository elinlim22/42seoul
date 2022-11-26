/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:11:22 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/26 22:07:04 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS	2
// # define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17
# define K_ESC	53
# define K_W	13
# define K_A	0
# define K_S	1
# define K_D	2

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		count;
}				t_game;

typedef struct s_tile
{
	void	*space;
	void	*star;
	void	*rocket;
	void	*wall;
	void	*exit;
}				t_tile;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}				t_map;

// parsing and checkers
void	map_par(t_map **ber, char *file);
int		check_ber(char *argv);
int		check_rect(t_map *ber);
int		check_wall(t_map *ber);
int		check_factors(t_map *ber);

// err_msg
void	err_msg(char *msg);

// tile
void	img_init(t_tile *tile, void *mlx);
void	draw_map(t_map *ber, t_game *game, t_tile *tile);

#endif
