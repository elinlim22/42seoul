/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:34:30 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/09 22:05:29 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int		res;
	t_node	*curr;

	curr = stack->stack_a;
	res = stack->stack_a->data;
	while (curr->next)
	{
		if (curr->data > res)
			res = curr->data;
		curr = curr->next;
	}
	return (res);
}

void	sort_three(t_stack *stack)
{
	int	max;

	max = find_max(stack);
	if (stack->stack_a->data == max)
		rotater(stack, 'a');
	if (stack->stack_a->next->data == max)
		rev_rotater(stack, 'a');
	if (stack->stack_a->data > stack->stack_a->next->data)
		swaper(stack, 'a');
}

void	sort_five(t_stack *stack, int count)
{
	int		min;
	int		i;
	int		state;
	t_node	*curr;

	if (count < 4)
		return ;
	curr = stack->stack_a->next;
	min = stack->stack_a->data;
	state = 0;
	while (curr->next)
	{
		if (curr->data < min)
		{
			min = curr->data;
			state = i;
		}
		curr = curr->next;
		i++;
	}
	sort_five_rot(stack, state);
	pusher(stack, 'b');
	sort_five(stack, --count);
}

void	sort_five_rot(t_stack *stack, int state)
{
	if (state <= 2)
	{
		while (state--)
			rotater(stack, 'a');
	}
	else
	{
		state = 5 - state;
		while (state--)
			rev_rotater(stack, 'a');
	}
}
