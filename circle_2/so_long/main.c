/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/21 16:56:37 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

void	map_par(char ***map, char *file)
{
	int	fd;
	char	*str;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		exit(write(1, "Error\n", 6));
	str = ft_strdup("");
	line = get_next_line(fd);
	while (line) //??
	{
		addstr(str, line);
		line = get_next_line(fd);
	}
	close(fd);
	*map = ft_split(str, '\n');
	free(str);
}

int	check_map(char ***map)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	while (*map[0]++)
		temp++;
	i = 1;
	while (*map[i])
	{
		j = 0;
		while (*map[i][j])
			j++;
		if (j != temp)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	// if ()
}
