/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:49:19 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/14 17:44:50 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int *arr, int count, t_stack *stacks);
char	**set_str(int argc, char *argv[]);
void	free_all(char **res, int size, t_stack *stacks);
int		count_args(char **res);
void	indexing(t_node **where, t_node *new);

void	init_stacks(int *arr, int count, t_stack *stacks)
{
	int	i;

	i = 0;
	stacks->stack_a = ft_db_lstnew(0, 0);
	stacks->stack_a->type = 0;
	while (i < count)
		indexing(&stacks->stack_a, ft_db_lstnew(arr[i++], 0));
	stacks->tail_a = ft_db_lstnew(0, 0);
	stacks->tail_a->type = 2;
	ft_db_lstadd_back(&stacks->stack_a, stacks->tail_a);
	stacks->stack_b = ft_db_lstnew(0, 0);
	stacks->stack_b->type = 0;
	stacks->tail_b = ft_db_lstnew(0, 0);
	stacks->tail_b->type = 2;
	ft_db_lstadd_back(&stacks->stack_b, stacks->tail_b);
	stacks->commands = ft_strdup("");
}

char	**set_str(int argc, char *argv[])
{
	char	*str;
	char	**res;
	int		i;
	char	*temp;

	i = 1;
	str = ft_strdup("");
	if (argc < 2)
		exit (0);
	while (i < argc)
	{
		if (*(argv[i]) == '\0')
			exit(write(1, "Error\n", 6));
		temp = str;
		str = ft_strjoin(temp, argv[i++]);
		free(temp);
		temp = str;
		str = ft_strjoin(temp, " ");
		free(temp);
	}
	res = ft_split(str, ' ');
	free(str);
	return (res);
}

void	free_all(char **res, int count, t_stack *stacks)
{
	if (stacks)
	{
		ft_db_lstclear(&(stacks->stack_a));
		ft_db_lstclear(&(stacks->stack_b));
		free(stacks->commands);
		free(stacks);
	}
	while (count--)
		free(res[count]);
	free(res);
	write(1, "Error\n", 6);
}

int	count_args(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	return (i);
}

void	indexing(t_node **where, t_node *new)
{
	t_node	*curr;

	curr = *where;
	while (curr->next)
	{
		if (curr->type == 1 && curr->data < new->data)
			(new->index)++;
		else if (curr->type == 1)
			(curr->index)++;
		curr = curr->next;
	}
	if (curr->type == 1 && curr->data < new->data)
		(new->index)++;
	else if (curr->type == 1)
		(curr->index)++;
	curr->next = new;
	new->prev = curr;
}
