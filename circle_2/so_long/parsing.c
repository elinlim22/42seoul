/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:57:52 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/27 23:53:45 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_par(t_map **ber, char *file);
int		check_ber(char *argv);
int		check_rect(t_map *ber);
int		check_wall(t_map *ber);
int		check_factors(t_map *ber);

void	map_par(t_map **ber, char *file)
{
	int		fd;
	char	*str;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		err_msg("cannot open the file");
	str = ft_strdup("");
	line = get_next_line(fd);
	(*ber)->width = (int)ft_strlen(line) - 1;
	while (line)
	{
		addstr(&str, line);
		line = get_next_line(fd);
	}
	close(fd);
	(*ber)->map = ft_split(str, '\n');
	(*ber)->height = ft_strlen_db((*ber)->map);
	free(line);
	free(str);
}

int	check_ber(char *argv)
{
	if (ft_strlen(ft_strnstr(argv, ".ber", ft_strlen(argv))) != 4)
		err_msg("not ber file");
	return (1);
}

int	check_rect(t_map *ber)
{
	int	i;

	i = 1;
	while (ber->map[i])
	{
		if ((int)ft_strlen(ber->map[i]) != ber->width)
			err_msg("not rectangular");
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
			err_msg("not surrounded by wall");
	}
	i = 0;
	while (ber->map[++i] && i < ber->height)
	{
		if (ber->map[i][len - 1] != '1' || ber->map[i][0] != '1')
			err_msg("not surrounded by wall");
	}
	i--;
	while (len--)
	{
		if (ber->map[i][len] != '1')
			err_msg("not surrounded by wall");
	}
	return (1);
}

int	check_factors(t_map *ber)
{
	int	exit;
	int	coll;
	int	posi;

	exit = count_coll(ber, 'E');
	coll = count_coll(ber, 'C');
	posi = count_coll(ber, 'P');
	if (exit != 1 || coll < 1 || posi != 1)
		err_msg("not proper components");
	return (1);
}
