/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:49:19 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/23 20:40:02 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int *arr, int count, t_stack *stacks)
{
	int	i;

	i = 0;
	stacks->stack_a = (t_node *)malloc(sizeof(t_node));
	if (!stacks->stack_a)
		exit(0);
	stacks->stack_a = ft_db_lstnew(NULL);
	while (i < count)
		ft_db_lstadd_back(&stacks->stack_a, ft_db_lstnew(arr[i++]));
	stacks->stack_b = (t_node *)malloc(sizeof(t_node));
	if (!stacks->stack_b)
		exit(0);
	stacks->stack_b = ft_db_lstnew(NULL);
	stacks->commands = ft_strdup("");
}
