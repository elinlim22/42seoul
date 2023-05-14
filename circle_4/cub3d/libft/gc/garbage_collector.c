/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:58:41 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/04 14:37:18 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	*ft_malloc(size_t size)
{
	return (primary(0, size, 'm'));
}

void	ft_free(void *addr)
{
	primary(addr, 0, 'f');
}

void	*ft_collect(void *addr)
{
	return (primary(addr, 0, 's'));
}

void	ft_clear(void)
{
	primary(0, 0, 'c');
}

void	*null_guard(void *addr)
{
	if (!addr)
		primary(0, 0, 'c');
	return (addr);
}
