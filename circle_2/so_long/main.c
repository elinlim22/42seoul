/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/20 20:36:04 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

void	map_par(char **map, char *file)
{
	int	fd;
	char	*str;

	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit(write(1, "Error\n", 6));
	str = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		addstr(str, line);
	}
	close(fd);

}

int	check_map(char **map)
{

}

