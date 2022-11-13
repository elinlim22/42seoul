/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/13 19:48:00 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h> //remove

typedef struct s_stack
{
	t_node	*stack_a; //head address
	t_node	*stack_b; //head address
	t_node	*tail_a;
	t_node	*tail_b;
	char	*commands;
}				t_stack;

// check.c
int		check_first(char **res);
int		*do_atoi(char **res, int size);
int		check_second(int *arr, int size);
int		check_sorted(int *arr, int size);

// commands.c
char	*swaper(t_stack *stacks, char a_or_b);
char	*pusher(t_stack *stacks, char a_or_b);
char	*rotater(t_stack *stacks, char a_or_b);
char	*rev_rotater(t_stack *stacks, char a_or_b);

// init.c
void	init_stacks(int *arr, int count, t_stack *stacks);
char	**set_str(int argc, char *argv[]);
void	free_all(char **res, int size, t_stack *stacks);
int		count_args(char **res);
void	indexing(t_node **where, t_node *new);

// push_pop.c
int		ft_push(t_node **where, t_node *popped);
t_node	*ft_pop(t_node **where, unsigned int index);

// sort_5.c
int		find_max(t_stack *stack);
int		find_node(t_stack *stack, int target);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack, int count);
void	sort_five_rot(t_stack *stack, int state, int count);

// push_swap.c
void	ps_b(t_stack *stack, int count, int num);
int		set_chunk(int count);
void	ps_a(t_stack *stack, int num);

#endif
