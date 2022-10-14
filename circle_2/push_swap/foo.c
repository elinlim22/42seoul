/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:24:05 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/14 21:43:54 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 전처리 */
char **set_str(int argc, char *argv[])
{
	char	*str;
	char	**res;
	int		i;

	str = ft_strdup("");
	if (argc < 2)
		exit (0);
	while (i < argc)
	{
		if (*(argv[i]) == '\0')
			exit(write(1, "Error\n", 6));
		str = ft_strjoin(str, argv[i++]);
		str = ft_strjoin(str, " ");
	}
	res = ft_split(str, ' ');
	return (res);
}

int	check_first(char **res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (res[i])
	{
		while (res[i][j])
		{
			if (!ft_isdigit(res[i][j]))
				return (0);
				// exit(0);
			else
				j++;
		}
		i++;
	}
	if (i < 2 && res[0] != NULL)
		exit(0);
	return (1);
}
