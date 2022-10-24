/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:43:05 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/23 20:39:58 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h> //remove

typedef struct	s_node
{
	t_node	*prev;
	t_node	*next;
	int		data;
}				t_node;

typedef struct	s_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*commands;
}				t_stack;

char	**set_str(int argc, char *argv[]);
int		check_first(char **res);
int		*do_atoi(char **res, int size);
int		check_second(int *arr, int size);
int		check_sorted(int *arr, int size);
void	free_all(char **res, int size);
int		count_args(char **res);
void	init_stacks(int *arr, int count, t_stack *stacks);
// t_stack	set_initial(int *arr, int count);
// t_all	*set_all(int count);

#endif
