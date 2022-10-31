/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:07:48 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/01 00:25:08 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 단축 : sa+sa, sb+sb, ss+ss, pa+pb, pb+pa, ra+rra, rb+rrb, rr+rrr */

/* push & pop 구현 */
int	ft_push(t_node **head, t_node *popped)
{
	//전체 자료 숫자 이상 넘어갈 시 오버플로우 예외처리(그럴일없을것같지만,,)
	//head 포인터가 가리키는 곳에 ft_db_lstadd_front하기
	if (!popped)
		return (0);
	else
	{
		ft_db_lstadd_front(head, popped);
		return (1);
	}
}

t_node	*ft_pop(t_node **head, unsigned int index) //고쳐.. 인덱스꺼 꺼내
{
	t_node	*target;
	int		res;

	//빈 리스트 예외처리
	if (!*head || !(*head)->next)
		return (NULL); //->pop실행안함 -> strjoin 실행x 예외처리
	target = *head;
	//두번째 리스트를 꺼낸..노우
	while (target->next && index--)
		target = target->next;
	if (!target->next)
		return (NULL);
	res = target->data;
	ft_db_lstdelone(target);
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
		res = "sa\n";
	}
	else if (a_or_b == 'b')
	{
		temp = stacks->stack_b;
		res = "sb\n";
	}
	else //ss 고려해야함,,
		return (NULL);
	popped = ft_pop(&temp, 2);
	if (!popped)
		return (NULL);
	ft_push(&temp, popped);
	return (res);
}

char	*pusher(t_stack *stacks, char a_or_b)
{
	t_node	*popped;
	// t_node	*target;
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		popped = ft_pop(&stacks->stack_b, 1);
		// if (!popped)
		// 	return (NULL);
		if (ft_push(&stacks->stack_a, popped)) //push가 실행되지 않았을 경우엔 res에 할당하면 안되는데..
			res = "pa\n";
	}
	else if (a_or_b == 'b')
	{
		popped = ft_pop(&stacks->stack_a, 1);
		// if (!popped)
		// 	return (NULL);
		if (ft_push(&stacks->stack_b, popped))
			res = "pb\n";
	}
	return (res);
}

// char	*rotater(t_stack *stacks, int dir, char a_or_b)
// {
// 	t_node	*temp;

// 	if (a_or_b == 'a')
// 		temp = ft_pop(stacks->stack_a, 1);
// 	if (dir == -1) //rr(?)
// 	{

// 	}
// 	else //r(?)
// }




/* sa, sb, ss */

/* pa, pb */

/* ra, rb, rr, rra, rrb, rrr */
