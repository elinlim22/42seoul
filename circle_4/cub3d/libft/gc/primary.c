/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primary.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:58:41 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/04 14:53:17 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

void	*primary(void *addr, size_t size, char flag)
{
	void			*res;
	static t_mem	**mem;

	if (flag == 'c')
		return (clear_mem(&mem));
	if (!mem)
		if (init_mems(&mem))
			return (0);
	if (flag == 'm' || flag == 's')
	{
		if (flag == 'm')
			res = malloc(size);
		else
			res = addr;
		if (!res)
			return (primary(0, 0, 'c'));
		res = gc_malloc(&(mem[(unsigned long long)res % 100]), res);
		if (!res)
			return (primary(0, 0, 'c'));
		return (res);
	}
	else if (flag == 'f')
		gc_free(&(mem[(unsigned long long)addr % 100]), addr);
	return (0);
}

void	*gc_malloc(t_mem **mem, void *res)
{
	t_mem	*cur;

	if (!mem_find(mem, res))
		return (res);
	if (!res)
		return (0);
	cur = new_mem(res);
	if (!cur)
	{
		free(res);
		return (0);
	}
	mem_add_front(mem, cur);
	return (res);
}

void	gc_free(t_mem **mem, void *addr)
{
	mem_del(mem, addr);
}

int	init_mems(t_mem ***mem)
{
	size_t	i;

	*mem = malloc(sizeof(t_mem *) * 100);
	if (!(*mem))
		return (1);
	i = 0;
	while (i < 100)
	{
		(*mem)[i] = 0;
		i++;
	}
	return (0);
}

void	*clear_mem(t_mem ***mem)
{
	size_t	i;

	if (!(*mem))
		return (0);
	i = 0;
	while (i < 100)
	{
		mem_clear(&((*mem)[i]));
		i++;
	}
	free(*mem);
	*mem = 0;
	return (0);
}
