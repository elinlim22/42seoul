/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:01:18 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 12:18:45 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stackpop(t_stack **stack)
{
	t_stack	*cur;
	int		res;

	cur = *stack;
	res = (*stack)->num;
	*stack = (*stack)->next;
	ft_free(cur);
	return (res);
}
