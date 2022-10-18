/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:15:26 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/18 16:42:37 by hyeslim          ###   ########.fr       */
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
int		*do_atoi(char **res, int count);
int		check_second(int *arr, int count);
int		check_sorted(int *arr, int count);
void	free_all(char **res, int count);
int		count_args(char **res);

// int	*arg_parsing(int argc, char *argv[]);

// typedef	struct s_index {
// 	int	idx;
// 	int
// }	t_index

#endif
