/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:07:48 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/12 16:50:31 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*swaper(t_stack *stacks, char a_or_b);
char	*pusher(t_stack *stacks, char a_or_b);
char	*rotater(t_stack *stacks, char a_or_b);
char	*rev_rotater(t_stack *stacks, char a_or_b);

/* 단축 : sa+sa, sb+sb, ss+ss, pa+pb, pb+pa, ra+rra, rb+rrb, rr+rrr */

char	*swaper(t_stack *stacks, char a_or_b)
{
	t_node	*temp;
	t_node	*popped;
	char	*res;

	if (a_or_b == 'a')
	{
		temp = stacks->stack_a;
		res = "sa\n";
	}
	else if (a_or_b == 'b')
	{
		temp = stacks->stack_b;
		res = "sb\n";
	}
	else
		return (NULL);
	popped = ft_pop(&temp, 2);
	if (!popped)
		return (NULL);
	ft_push(&temp, popped);
	return (res);
}

char	*pusher(t_stack *stacks, char a_or_b)
{
	t_node	*popped;
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		popped = ft_pop(&stacks->stack_b, 1);
		if (ft_push(&stacks->stack_a, popped))
			res = "pa\n";
	}
	else if (a_or_b == 'b')
	{
		popped = ft_pop(&stacks->stack_a, 1);
		if (ft_push(&stacks->stack_b, popped))
			res = "pb\n";
	}
	return (res);
}

char	*rotater(t_stack *stacks, char a_or_b)
{
	t_node	*popped;
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		popped = ft_pop(&stacks->stack_a, 1);
		if (ft_push(&stacks->tail_a, popped))
			res = "ra\n";
	}
	else if (a_or_b == 'b')
	{
		popped = ft_pop(&stacks->stack_b, 1);
		if (ft_push(&stacks->tail_b, popped))
			res = "rb\n";
	}
	return (res);
}

char	*rev_rotater(t_stack *stacks, char a_or_b)
{
	t_node	*popped;
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		popped = ft_pop(&stacks->tail_a, 1);
		if (ft_push(&stacks->stack_a, popped))
			res = "rra\n";
	}
	else if (a_or_b == 'b')
	{
		popped = ft_pop(&stacks->tail_b, 1);
		if (ft_push(&stacks->stack_b, popped))
			res = "rrb\n";
	}
	return (res);
}

/* sa, sb, ss */

/* pa, pb */

/* ra, rb, rr, rra, rrb, rrr */
