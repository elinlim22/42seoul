/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:11:22 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/24 17:01:09 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct	s_map
{
	char	**map;
	int		hight;
	int		width;
}				t_map;

typedef struct	s_tile
{
	void	*space;
	void	*star;
	void	*rocket;
	void	*wall;
	void	*exit;
}				t_tile;

// parsing and checkers
void	map_par(t_map **ber, char *file);
int		check_ber(char *argv);
int		check_rect(t_map *ber);
int		check_wall(t_map *ber);
int		check_factors(t_map *ber);

// err_msg
void	err_msg(char *msg);

// tile

#endif
