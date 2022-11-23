/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:21:50 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/23 20:52:03 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://velog.io/@chez_bono/solong-zq9xy27q

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

#include <stdio.h>
int	main(int argc __attribute__((unused)), char *argv[])
{
	t_map	*ber;

	ber = (t_map *)malloc(sizeof(t_map));
	map_par(&ber, argv[1]); // 메모리 누수 오져요~
	int	i = 0, j = 0;
	while (ber->map[i++])
		j++;
	for (int i = 0; i < j; i++)
		printf("%s\n", ber->map[i]);
	printf("check_ber : %d\n", check_ber(argv[1]));
	printf("check_rect : %d\n", check_rect(ber));
	printf("check_wall : %d\n", check_wall(ber));
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_loop(mlx);
// }

