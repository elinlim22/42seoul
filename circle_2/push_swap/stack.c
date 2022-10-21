/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:51:25 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/21 18:42:39 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	set_initial(int *arr, int count)
{
	t_stack	initial;
	int		i;

	i = 0;
	while (i < count)
	{
		initial.stack[i].num = arr[i];
		initial.stack[i].flag = 1;
		i++;
	}
	return (initial);
}

t_all	*set_all(int count)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->stack_a->stack = (int *)malloc(sizeof(int) * count);
	all->stack_a->count = count;
	all->stack_b->stack = (int *)malloc(sizeof(int) * count);
	all->stack_b->count = 0;
	all->command = ft_strdup("");

	return (all);
}

// t_stack	check_all(char **res, int *arr, int count) ///목적 : main의 역할을 할 setup.. check역할 필요
// {
// 	t_stack	initial;
// 	int		*arr;

// 	if (check_first(res))
// 	{
// 		initial.count = size_args(res);
// 		arr = do_atoi(res, count);
// 		initial = set_initial(arr, count);
// 		// set.stack = do_atoi(res, size); //xxxxx
// 		if (!check_second(set.stack, set.count) || !check_sorted(set.stack, set.count))
// 		{

// 		}
// 	}

// 	return (set);
// }
