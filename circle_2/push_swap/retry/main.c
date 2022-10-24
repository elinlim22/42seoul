/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:34:30 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/24 15:16:35 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**res;
	int		count;
	t_stack	*stacks;
	int		*arr;

	res = set_str(argc, argv);
	if (!res)
		return (0);
	count = count_args(res);
	if (check_first(res))
	{
		arr = do_atoi(res, count);
		stacks = (t_stack *)malloc(sizeof(t_stack));
		init_stacks(arr, count, stacks);
		if (!check_second(arr, count) || !check_sorted(arr, count))
			exit(write(1, "Error\n", 6));
		else
		{
			// sorting(모래시계 정렬 함수);
			ft_putstr_fd(stacks->commands, 1);
			//commands strjoin한거 free하기
			free_all(res, count); //stack도 free필요
			free(arr);
		}
	}
	else
		free_all(res, count);
	exit (0);
}
