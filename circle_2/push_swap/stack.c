/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:51:25 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/19 18:43:33 by hyeslim          ###   ########.fr       */
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

void	set_stack(t_stack set)
{
	t_all	*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->stack_a->stack = (int *)malloc(sizeof(int) * set.count);
	all->stack_a->count = set.count;
	all->stack_b->stack = (int *)malloc(sizeof(int) * set.count);
	all->stack_b->count = 0;
	all->command = ft_strdup("");
}

