/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:34:30 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/01 00:26:10 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* 필요한 파일인가? */



// #include "push_swap.h"

// void	setup(int argc, char *argv[]) //이 모든게 setup이 아닌가..?
// {
// 	char	**res;
// 	int		count;
// 	t_stack	*stacks;
// 	int		*arr;

// 	res = set_str(argc, argv);
// 	if (!res)
// 		return (0);
// 	count = count_args(res);
// 	if (check_first(res))
// 	{
// 		arr = do_atoi(res, count);
// 		stacks = (t_stack *)malloc(sizeof(t_stack));
// 		init_stacks(arr, count, stacks);
// 		if (!check_second(arr, count) || !check_sorted(arr, count))
// 			exit(write(1, "Error\n", 6));
// 		else
// 		{
// 			// commands_tester;
// 			// sorting(모래시계 정렬 함수);
// 			// ft_putstr_fd(stacks->commands, 1);
// 			free_all(res, count, stacks);
// 			free(arr);
// 		}
// 	}
// 	else
// 		free_all(res, count, NULL);
// 	// return (0);
// }
