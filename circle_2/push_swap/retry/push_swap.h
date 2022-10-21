/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:43:05 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/21 18:49:06 by hyeslim          ###   ########.fr       */
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

#endif
