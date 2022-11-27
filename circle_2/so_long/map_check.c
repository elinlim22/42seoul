/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:03:45 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/27 23:51:29 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_memcpy(char ***dest, char **src, int height);
int		validity(t_game *game);
void	map_check(t_game *game, t_chk *chk, int x, int y);

void	sl_memcpy(char ***dest, char **src, int height)
{
	int	i;
	int	j;

	if (!(*dest) && !src)
		return ;
	if ((*dest) == src)
		return ;
	(*dest) = (char **)malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (src[i])
	{
		(*dest)[i] = (char *)malloc(sizeof(char) * (ft_strlen(src[i]) + 1));
		j = -1;
		while (src[i][++j])
			(*dest)[i][j] = src[i][j];
		(*dest)[i][j] = '\0';
		i++;
	}
	(*dest)[i] = NULL;
}

int	validity(t_game *game)
{
	t_chk	chk;

	sl_memcpy(&(chk.map), game->ber->map, game->ber->height);
	chk.exit = 0;
	chk.star = 0;
	map_check(game, &chk, game->x, game->y);
	if (chk.exit != 1 || (chk.star != game->ber->coll))
		err_msg("the map has no valid path");
	return (1);
}

void	map_check(t_game *game, t_chk *chk, int x, int y)
{
	const int	arr[4][2] = {{(x - 1), y}, {x, (y - 1)}, {x, (y + 1)}, {(x + 1), y}};
	int			i;

	i = 0;
	if (!(x <= 0 || y <= 0 || x >= game->ber->width || y >= game->ber->height))
	{
		while (i < 4)
		{
			chk->map[y][x] = '1';
			if (chk->map[arr[i][1]][arr[i][0]] == '1')
			{
				i++;
				continue ;
			}
			else if (chk->map[arr[i][1]][arr[i][0]] == 'C')
			{
				chk->star++;
				map_check(game, chk, arr[i][0], arr[i][1]);
			}
			else if (chk->map[arr[i][1]][arr[i][0]] == 'E')
			{
				chk->exit++;
				map_check(game, chk, arr[i][0], arr[i][1]);
			}
			else
				map_check(game, chk, arr[i][0], arr[i][1]);
		}
		return ;
	}
}
