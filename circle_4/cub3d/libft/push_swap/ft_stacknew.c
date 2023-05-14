/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:18:47 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/03 12:18:38 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_stack	*ft_stacknew(int num)
{
	t_stack	*res;

	res = ft_malloc(sizeof(t_stack));
	if (!res)
		return (0);
	res->num = num;
	res->next = 0;
	return (res);
}
