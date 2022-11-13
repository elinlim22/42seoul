/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:49:32 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/13 15:36:45 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_push(t_node **where, t_node *popped);
t_node	*ft_pop(t_node **where, unsigned int index);

	//전체 자료 숫자 이상 넘어갈 시 오버플로우 예외처리(그럴일없을것같지만,,)
	//head 포인터가 가리키는 곳에 ft_db_lstadd_front하기
/* push & pop 구현 */
int	ft_push(t_node **where, t_node *popped)
{
	if (!popped)
		return (0);
	else if ((*where)->type == 0)
	{
		ft_db_lstadd_front(where, popped);
		return (1);
	}
	else if ((*where)->type == 2)
	{
		ft_db_lstadd_back(where, popped);
		return (1);
	}
	else
		return (0);
}

t_node	*ft_pop(t_node **where, unsigned int index)
{
	t_node	*target;
	int		res;
	int		idx;

	target = *where;
	if (!*where)
		return (NULL);
	if ((*where)->type == 0)
	{
		while (target->next && index--)
			target = target->next;
	}
	else if ((*where)->type == 2)
	{
		while (target->prev && index--)
			target = target->prev;
	}
	else
		return (NULL);
	res = target->data;
	idx = target->index;
	ft_db_lstdelone(target);
	target = ft_db_lstnew(res, idx);
	return (target);
}
