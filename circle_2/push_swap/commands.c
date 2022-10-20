/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 20:15:24 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/20 10:48:46 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swaper(t_stack *target)
{
	t_data	temp;

	temp = target->stack[0];
	target->stack[0] = target->stack[1];
	target->stack[1] = temp;
}

int	sa(t_all *all)
{
	swaper(all->stack_a);
	ft_strjoin(all->command, "sa\n");

	return (0);
}

int	sb(t_all *all)
{
	swaper(all->stack_b);
	ft_strjoin(all->command, "sb\n");

	return (0);
}

int	ss(t_all *all)
{
	swaper(all->stack_a);
	swaper(all->stack_b);
	ft_strjoin(all->command, "ss\n");

	return (0);
}

void	pusher(t_stack *src, t_stack *dst, int size) ///size 말고 stack->count
{
	t_data	temp;
	int		i;

	i = 0;
	temp = src->stack[0];
	while ((i + 1) < size)
	{
		src->stack[i] = src->stack[i + 1];
		i++;
	}
	src->count -= 1;
	while (i > 0)
	{
		dst->stack[i] = dst->stack[i - 1];
		i--;
	}
	dst->count += 1;
	dst->stack[0] = temp;
}

int	pa(t_all *all, t_stack *initial)
{
	pusher(all->stack_b, all->stack_a, initial->count);
	ft_strjoin(all->command, "pa\n");

	return (0);
}

int	pb(t_all *all, t_stack *initial)
{
	pusher(all->stack_a, all->stack_a, initial->count);
	ft_strjoin(all->command, "pb\n");

	return (0);
}

void	rotater(t_stack *target, int direction)
{
	t_data	temp;
	int		i;

	i = 0;
	if (direction == -1) //rotate up
	{
		temp = target->stack[0];
		while ((i + 1) < target->count)
		{
			target->stack[i] = target->stack[i + 1];
			i++;
		}
		target->stack[i] = temp;
	}
	else if (direction == 1) //rotate down : rra/rrb/rrr
	{
		i = target->count;
		temp = target->stack[i - 1];
		while (i > 0)
		{

		}
	}
}
