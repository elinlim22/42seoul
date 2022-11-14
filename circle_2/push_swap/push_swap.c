/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:48:17 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/14 15:59:38 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		set_chunk(int count);
void	addstr(t_stack *stack, char *str);
void	ps_b(t_stack *stack, int count, int num);
void	ps_a(t_stack *stack, int count);

int	set_chunk(int count)
{
	if (count <= 30)
		return (5);
	if (count <= 100)
		return (10);
	if (count <= 500)
		return (30);
	if (count <= 1000)
		return (45);
	if (count <= 2000)
		return (65);
	if (count <= 5000)
		return (300);
	else
		return (300);
}

void	addstr(t_stack *stack, char *str)
{
	char	*dst;

	dst = stack->commands;
	stack->commands = ft_strjoin(dst, str);
	free(dst);
}

void	ps_b(t_stack *stack, int count, int num)
{
	int		chunk;
	t_node	*curr;

	chunk = set_chunk(count);
	curr = stack->stack_a->next;
	while (curr->type == 1)
	{
		if (curr->index > num + chunk)
		{
			addstr(stack, rotater(stack, 'a'));
			curr = curr->next;
		}
		else
		{
			addstr(stack, pusher(stack, 'b'));
			if (curr->index >= num && curr->index <= num + chunk)
				addstr(stack, rotater(stack, 'b'));
			curr = stack->stack_a->next;
			count--;
			num++;
		}
	}
	if (stack->stack_a->next->type == 1)
		ps_b(stack, count, num);
	return ;
}

void	ps_a(t_stack *stack, int count)
{
	t_node	*curr;
	int		where;

	curr = stack->stack_b->next;
	while (curr->type == 1)
	{
		where = find_node(stack, count - 1);
		if (where)
		{
			if (where < count / 2)
			{
				while (where--)
					addstr(stack, rotater(stack, 'b'));
			}
			else if (where >= count / 2)
			{
				where = count - where;
				while (where--)
					addstr(stack, rev_rotater(stack, 'b'));
			}
		}
		addstr(stack, pusher(stack, 'a'));
		count--;
		curr = stack->stack_b->next;
	}
}
