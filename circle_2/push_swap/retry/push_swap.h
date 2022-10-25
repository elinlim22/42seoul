/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:43:05 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/25 16:33:38 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h> //remove

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				data;
}				t_node;

typedef struct s_stack
{
	t_node	*stack_a; //head address
	t_node	*stack_b; //head address
	t_node	*tail_a;
	t_node	*tail_b;
	char	*commands;
}				t_stack;

char	**set_str(int argc, char *argv[]);
int		check_first(char **res);
int		*do_atoi(char **res, int size);
int		check_second(int *arr, int size);
int		check_sorted(int *arr, int size);
void	free_all(char **res, int size, t_stack *stacks);
int		count_args(char **res);
void	init_stacks(int *arr, int count, t_stack *stacks);
// t_stack	set_initial(int *arr, int count);
// t_all	*set_all(int count);

#endif
