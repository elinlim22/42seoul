/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:57:52 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/23 20:58:17 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_par(t_map **ber, char *file);
int		check_ber(char *argv);
int		check_rect(t_map *ber);
int		check_wall(t_map *ber);

void	map_par(t_map **ber, char *file)
{
	int		fd;
	char	*str;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit(write(1, "Error\n", 6));
	str = ft_strdup("");
	line = get_next_line(fd);
	(*ber)->width = (int)ft_strlen(line) - 1;
	while (line) //??
	{
		addstr(&str, line);
		line = get_next_line(fd);
	}
	close(fd);
	(*ber)->map = ft_split(str, '\n');
	(*ber)->hight = ft_strlen_db((*ber)->map);
	free(line);
	free(str);
}

int	check_ber(char *argv)
{
	if (ft_strlen(ft_strnstr(argv, ".ber", ft_strlen(argv))) != 4)
		return (0);
	return (1);
}

int	check_rect(t_map *ber)
{
	int	i;

	i = 1;
	while (ber->map[i])
	{
		if ((int)ft_strlen(ber->map[i]) != ber->width)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_map *ber)
{
	int	len;
	int	i;

	len = (int)ft_strlen(ber->map[0]);
	i = 0;
	while (i < len)
	{
		if (ber->map[0][i++] != '1')
			return (0);
	}
	i = 0;
	while (ber->map[++i] && i < ber->hight)
	{
		if (ber->map[i][len - 1] != '1' || ber->map[i][0] != '1')
			return (0);
	}
	i--;
	while (len--)
	{
		if (ber->map[i][len] != '1')
			return (0);
	}
	return (1);
}
