/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:49:19 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/09 20:11:53 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(int *arr, int count, t_stack *stacks);
char	**set_str(int argc, char *argv[]);
void	free_all(char **res, int size, t_stack *stacks);
int		count_args(char **res);
int		*indexing(int *arr, int count);

void	init_stacks(int *arr, int count, t_stack *stacks)
{
	int	i;

	i = 0;
	/* indexing */
	stacks->index = indexing(arr, count);
	if (!stacks->index)
		exit(0);
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
	int	i;

	i = 0;
	if (!stacks)
	{
		ft_db_lstclear(&(stacks->stack_a));
		ft_db_lstclear(&(stacks->stack_b));
		free(stacks->commands);
		free(stacks->index);
		free(stacks);
	}
	while (i < count)
	{
		printf("freeing cell no.%d : %s\n", i, res[i]);
		free(res[i++]);
	}
	free(res);
}

int	count_args(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		i++;
	printf("size_args : %d\n", i);
	return (i);
}

int	*indexing(int *arr, int count)
{
	int	*index;
	int	i;

	i = -1;
	index = (int *)malloc(sizeof(int) * count);
	if (!index)
		return (0);
	while (++i < count)
	{
		index[i] = arr[i];
	}
	i = -1;
	ft_sort(index, count);
	return (index);
}
