/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:50:51 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/14 17:43:50 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack, int count);
int		main(int argc, char *argv[]);

void	push_swap(t_stack *stack, int count)
{
	if (count > 5)
	{
		ps_b(stack, count, 0);
		ps_a(stack, count);
	}
	else
	{
		sort_five(stack, count);
		sort_three(stack);
		count -= 3;
		while (count--)
			addstr(stack, pusher(stack, 'a'));
	}
}

int	main(int argc, char *argv[])
{
	char	**res;
	int		count;
	int		*arr;
	t_stack	*stack;

	res = set_str(argc, argv);
	count = count_args(res);
	if (check_first(res))
	{
		arr = do_atoi(res, count);
		stack = (t_stack *)malloc(sizeof(t_stack));
		init_stacks(arr, count, stack);
		if (!check_second(arr, count))
			exit(write(1, "Error\n", 6));
		else if (!check_sorted(arr, count))
			exit(0);
		push_swap(stack, count);
		ft_putstr_fd(stack->commands, 1);
	}
	else
		free_all(res, count, NULL);
	return (0);
}
