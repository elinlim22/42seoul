/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:49:19 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/03 16:29:44 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int *arr, int count, t_stack *stacks)
{
	int	i;

	i = 0;
	/* stack a setting... */
	stacks->stack_a = ft_db_lstnew(0); //head
	stacks->stack_a->type = 0;
	while (i < count)
		ft_db_lstadd_back(&stacks->stack_a, ft_db_lstnew(arr[i++]));
	stacks->tail_a = ft_db_lstnew(0);
	stacks->tail_a->type = 2;
	ft_db_lstadd_back(&stacks->stack_a, stacks->tail_a); //tail
	/* stack b setting... */
	stacks->stack_b = ft_db_lstnew(0); //head
	stacks->stack_b->type = 0;
	stacks->tail_b = ft_db_lstnew(0);
	stacks->tail_b->type = 2;
	ft_db_lstadd_back(&stacks->stack_b, stacks->tail_b); //tail
	/* commands setting... */
	stacks->commands = ft_strdup("");
}
