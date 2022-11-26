/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:04:58 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/27 01:05:00 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mv_w(t_game *game, t_map *ber)
{
	int	temp;

	temp = game->y - ber->width;
	if (temp < 0)
		return ;
	// ber->map[game->y, game->x] = '0';
	if (ber->map[temp, game->x] != '1')
	{
		if (ber->map[temp, game->x] != 'E')
		{
			game->y = temp;
			ber->map[game->y, game->x] = 'P';
		}
		else
			return ; // 출구면? 게임 종료?
	}
	return ; // 벽면이면 그냥 아무것도 하지 않음
}
