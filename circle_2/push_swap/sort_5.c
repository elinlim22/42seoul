/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:34:30 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/16 17:01:16 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_max(t_stack *stack);
int		find_node(t_stack *stack, int target);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack, int count);
void	sort_five_rot(t_stack *stack, int state, int count);

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

int	find_node(t_stack *stack, int target)
{
	t_node	*curr;
	int		w;

	curr = stack->stack_b->next;
	w = 0;
	while (curr->type == 1)
	{
		if (curr->index == target)
			break ;
		else
		{
			curr = curr->next;
			w++;
		}
	}
	return (w);
}

void	sort_three(t_stack *stack)
{
	int	max;

	max = find_max(stack);
	if (stack->stack_a->next->data == max)
		addstr(stack, rotater(stack, 'a'));
	if (stack->stack_a->next->next->data == max)
		addstr(stack, rev_rotater(stack, 'a'));
	if (stack->stack_a->next->data > stack->stack_a->next->next->data)
		addstr(stack, swaper(stack, 'a'));
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
	min = curr->data;
	state = 0;
	i = 0;
	while (curr->type == 1)
	{
		if (curr->data < min)
		{
			min = curr->data;
			state = i;
		}
		curr = curr->next;
		i++;
	}
	sort_five_rot(stack, state, count);
	addstr(stack, pusher(stack, 'b'));
	sort_five(stack, --count);
}

void	sort_five_rot(t_stack *stack, int state, int count)
{
	if (state <= 2)
	{
		while (state--)
			addstr(stack, rotater(stack, 'a'));
	}
	else
	{
		state = count - state;
		while (state--)
			addstr(stack, rev_rotater(stack, 'a'));
	}
}
