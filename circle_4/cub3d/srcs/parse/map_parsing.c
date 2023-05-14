/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:20:48 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/14 16:09:45 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	map_atoi(char c, int *val)
{
	if (c == '0')
		*val = 0;
	else if (c == '1')
		*val = 1;
	else if (c == '2')
		*val = SPRITE;
	else if (c == 'N')
		*val = NORTH;
	else if (c == 'S')
		*val = SOUTH;
	else if (c == 'W')
		*val = WEST;
	else if (c == 'E')
		*val = EAST;
	else if (c == '7')
		*val = DOOR_C;
	else if (c == '8')
		*val = DOOR_O;
	else if (c != ' ')
		return (false);
	return (true);
}

t_arg	*init_map(t_arg *arg)
{
	int	i;
	int	j;

	i = -1;
	while (++i < arg->y_size)
	{
		j = -1;
		while (++j < arg->x_size)
		{
			arg->map[i][j].val = -1;
			arg->map[i][j].x = j;
			arg->map[i][j].y = i;
		}
	}
	return (arg);
}

t_arg	*get_map(t_list *map_list, t_arg *arg)
{
	int		i;
	int		j;
	t_list	*curr;

	curr = map_list;
	i = 0;
	arg = init_map(arg);
	while (curr)
	{
		j = -1;
		while (curr->str[++j])
		{
			if (!map_atoi(curr->str[j], &(arg->map[i][j].val)))
			{
				free_list(map_list);
				free_all(arg);
				exit(ft_putendl_fd("Wrong map argument!", 1));
			}
		}
		i++;
		curr = curr->next;
	}
	free_list(map_list);
	return (arg);
}

t_arg	*malloc_map(t_list *map_list, t_arg *arg)
{
	int		y;
	t_list	*curr;

	y = 0;
	curr = map_list;
	arg->x_size = curr->x_size;
	arg->y_size = ft_lstsize(curr);
	while (curr)
	{
		if (curr->x_size > arg->x_size)
			arg->x_size = curr->x_size;
		curr = curr->next;
	}
	arg->map = malloc(sizeof(t_map *) * arg->y_size);
	if (!arg->map)
		exit(ft_putendl_fd("Malloc error!", 1));
	while (y < arg->y_size)
	{
		arg->map[y] = malloc(sizeof(t_map) * arg->x_size);
		if (!arg->map[y])
			exit(ft_putendl_fd("Malloc error!", 1));
		y++;
	}
	arg = get_map(map_list, arg);
	return (arg);
}

void	map_parsing(t_arg *arg, int fd)
{
	int		i;
	char	*tmp;
	t_list	*map_list;

	i = 0 ;
	map_list = NULL;
	tmp = get_next_line(fd);
	if (!tmp)
	{
		free_arg(arg);
		exit(ft_putendl_fd("Gnl error!", 1));
	}
	while (tmp)
	{
		if (tmp[0] != '\n')
		{
			i++;
			ft_lstadd_back(&map_list, ft_lstnew(ft_strdup(tmp), i));
		}
		else if (tmp[0] == '\n' && map_list)
			exit_map(arg, map_list);
		free(tmp);
		tmp = get_next_line(fd);
	}
	arg = malloc_map(map_list, arg);
}
