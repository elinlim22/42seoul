/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:07:48 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/25 22:27:49 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 단축 : sa+sa, sb+sb, ss+ss, pa+pb, pb+pa, ra+rra, rb+rrb, rr+rrr */

/* push & pop 구현 */
int	ft_push(t_node **head, t_node *node)
{
	//전체 자료 숫자 이상 넘어갈 시 오버플로우 예외처리(그럴일없을것같지만,,)
	//head 포인터가 가리키는 곳에 ft_db_lstadd_front하기
	if (node)
	{
		ft_db_lstadd_front(&head, node);
		return (1);
	}
	else
		return (0);
}

t_node	*ft_pop(t_node **head)
{
	t_node	*target;
	int		res;

	//빈 리스트 예외처리
	if (!*head)
		return (NULL); //->pop실행안함 -> strjoin 실행x 예외처리
	//두번째 리스트를 꺼낸다
	res = (*head)->next->next->data;
	ft_db_lstdelone((*head)->next->next);
	target = ft_db_lstnew(res);
	return (target);
}

char	*swaper(t_stack *stacks, char a_or_b)
{
	t_node	*temp;
	t_node	*popped;
	char	*res;

	if (a_or_b == 'a')
	{
		temp = stacks->stack_a;
		res = "sa";
	}
	else if (a_or_b == 'b')
	{
		temp = stacks->stack_b;
		res = "sb";
	}
	else //ss 고려해야함,,
		return (NULL);
	popped = ft_pop(temp);
	if (!popped)
		return (NULL);
	ft_push(&temp, popped);
	return (res);
}

char	*pusher(t_stack *stacks, char a_or_b)
{
	t_node	*temp;
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		temp = ft_pop(stacks->stack_b);
		if (ft_push(stacks->stack_a, temp)) //push가 실행되지 않았을 경우엔 res에 할당하면 안되는데..
			res = "pa";
	}
	else if (a_or_b == 'b')
	{
		temp = ft_pop(stacks->stack_a);
		if (ft_push(stacks->stack_b, temp))
			res = "pb";
	}
	else
		res = NULL;
	return (res);
}

char	*rotater(t_stack *stacks, int dir)
{
	if (dir == -1) //rr
}




/* sa, sb, ss */

/* pa, pb */

/* ra, rb, rr, rra, rrb, rrr */
