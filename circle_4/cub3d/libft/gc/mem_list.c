/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongyoki <dongyoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:18:47 by dongyoki          #+#    #+#             */
/*   Updated: 2022/12/04 14:53:22 by dongyoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "garbage_collector.h"

t_mem	*new_mem(void *addr)
{
	t_mem	*mem;

	mem = malloc(sizeof(t_mem));
	if (!mem)
		return (0);
	mem->addr = addr;
	mem->next = 0;
	return (mem);
}

void	mem_add_front(t_mem **mem, t_mem *new)
{
	new->next = *mem;
	*mem = new;
}

void	mem_del(t_mem **mem, void *addr)
{
	t_mem	*cur;
	t_mem	*pre;

	cur = *mem;
	pre = 0;
	while (cur && (cur->addr) != addr)
	{
		pre = cur;
		cur = cur->next;
	}
	if (!cur)
	{
		free(addr);
		return ;
	}
	if (pre && cur)
		pre->next = cur->next;
	else if (!pre && cur)
		*mem = cur->next;
	free(cur->addr);
	free(cur);
}

void	mem_clear(t_mem **mem)
{
	t_mem	*cur;

	if (!(*mem))
		return ;
	while (*mem)
	{
		cur = *mem;
		*mem = (*mem)->next;
		free(cur->addr);
		free(cur);
	}
}

void	*mem_find(t_mem **mem, void *addr)
{
	t_mem	*tmp;

	tmp = *mem;
	if (!tmp)
		return (addr);
	while (tmp)
	{
		if (tmp->addr == addr)
			return (0);
		tmp = tmp->next;
	}
	return (addr);
}
