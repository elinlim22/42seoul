/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/03 16:38:42 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h> //remove

// typedef struct s_node
// {
// 	struct s_node	*prev;
// 	struct s_node	*next;
// 	int				data;
// }				t_node;

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

int	ft_push(t_node **where, t_node *popped);
t_node	*ft_pop(t_node **where, unsigned int index);
char	*swaper(t_stack *stacks, char a_or_b);
char	*pusher(t_stack *stacks, char a_or_b);
char	*rotater(t_stack *stacks, char a_or_b);
char	*rev_rotater(t_stack *stacks, char a_or_b);

#endif
