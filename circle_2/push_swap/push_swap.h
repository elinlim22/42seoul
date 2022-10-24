/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/24 15:19:38 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h> //필요?
# include "libft/libft.h"

// typedef struct s_data
// {
// 	int	num;
// 	int	flag;
// }				t_data;

// typedef struct	s_stack
// {
// 	t_data	*stack;
// 	int	count;
// }				t_stack;

typedef struct s_node
{
	t_node	*prev;
	t_node	*next;
	int		data;
}				t_node;

typedef struct	s_stack
{
	t_node		*stack_a;
	t_node		*stack_b;
	char		*command;
}				t_stack;

char	**set_str(int argc, char *argv[]);
int		check_first(char **res);
int		*do_atoi(char **res, int size);
int		check_second(int *arr, int size);
int		check_sorted(int *arr, int size);
void	free_all(char **res, int count, t_stack *stacks);
int		count_args(char **res);
// t_stack	set_initial(int *arr, int count);
// t_all	*set_all(int count);
// t_stack	check_all(char **res, int *arr, int count);

#endif
