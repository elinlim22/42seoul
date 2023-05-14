/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:04:51 by dongyoki          #+#    #+#             */
/*   Updated: 2022/11/29 22:43:57 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_stackpush(t_stack **stack, int num)
{
	t_stack	*new;

	new = ft_stacknew(num);
	if (!new)
		return (1);
	ft_stack_add(stack, new);
	return (0);
}
