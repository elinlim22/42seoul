/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/20 13:54:16 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h> //필요?
# include "libft/libft.h"

typedef struct s_data
{
	int	num;
	int	flag;
}				t_data;

typedef struct	s_stack
{
	t_data	*stack;
	int	count;
}				t_stack;

typedef struct	s_all
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*command;
}				t_all;

char	**set_str(int argc, char *argv[]);
int		check_first(char **res);
t_data	*do_atoi(char **res, int size);
int		check_second(int *arr, int size);
int		check_sorted(int *arr, int size);
void	free_all(char **res, int size);
int		size_args(char **res);

#endif
