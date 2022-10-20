/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/19 17:12:05 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h> //필요?
# include "libft/libft.h"

char	**set_str(int argc, char *argv[]);
int		check_first(char **res);
int		*do_atoi(char **res, int size);
int		check_second(int *arr, int size);
int		check_sorted(int *arr, int size);
void	free_all(char **res, int size);
int		size_args(char **res);

// int	*arg_parsing(int argc, char *argv[]);

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

#endif
