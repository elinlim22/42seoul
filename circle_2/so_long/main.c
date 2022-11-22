/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/22 15:54:11 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

#include "so_long.h"

void	map_par(char ***map, char *file);
int		check_rect(char ***map);
int		check_ber(char *argv);

void	map_par(char ***map, char *file)
{
	int		fd;
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

int	check_rect(char ***map)
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

int	check_ber(char *argv)
{
	if (ft_strlen(ft_strnstr(argv, ".ber", ft_strlen(argv))) != 4)
		return (0);
	return (1);
}
// #include <stdio.h>
// int	main(int argc __attribute__((unused)), char *argv[])
// {
// 	printf("res : %d\n", check_ber(argv[1]));
// 	return (0);
// }


int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}
