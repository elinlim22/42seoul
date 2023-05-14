/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:02:38 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 12:18:35 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_stackclear(t_stack **stack)
{
	t_stack	*cur;

	if (!(*stack))
		return ;
	while (*stack)
	{
		cur = *stack;
		*stack = (*stack)->next;
		ft_free(cur);
	}
}
