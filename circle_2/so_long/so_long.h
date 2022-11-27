/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:11:22 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/27 23:43:57 by hyeslim          ###   ########.fr       */
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
	int		coll;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	int		count;
	t_map	*ber;
	t_tile	tile;
}				t_game;

typedef struct s_chk
{
	char	**map;
	int		star;
	int		exit;
}				t_chk;

// parsing and checkers
void	map_par(t_map **ber, char *file);
int		check_ber(char *argv);
int		check_rect(t_map *ber);
int		check_wall(t_map *ber);
int		check_factors(t_map *ber);

// err_msg
void	err_msg(char *msg);
int		exit_game(t_game *game);
int		key(int k, t_game *game);
void	locate_p(t_game *game);

// tile
void	img_init(t_tile *tile, void *mlx);
void	draw_map(t_game *game);
int		count_coll(t_map *ber, char c);


// key
void	mv_w(t_game *game);
void	mv_a(t_game *game);
void	mv_s(t_game *game);
void	mv_d(t_game *game);

// map_check
void	sl_memcpy(char ***dest, char **src, int height);
int		validity(t_game *game);
void	map_check(t_game *game, t_chk *chk, int x, int y);

#endif
