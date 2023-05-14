/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacksize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:49:40 by dongyoki          #+#    #+#             */
/*   Updated: 2022/11/25 13:28:37 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_stacksize(t_stack *stack)
{
	int	res;

	res = 0;
	while (stack)
	{
		res++;
		stack = stack->next;
	}
	return (res);
}
