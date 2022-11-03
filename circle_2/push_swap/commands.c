/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:07:48 by hyeslim           #+#    #+#             */
/*   Updated: 2022/11/03 16:30:01 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 단축 : sa+sa, sb+sb, ss+ss, pa+pb, pb+pa, ra+rra, rb+rrb, rr+rrr */

/* push & pop 구현 */
int	ft_push(t_node **where, t_node *popped)
{
	//전체 자료 숫자 이상 넘어갈 시 오버플로우 예외처리(그럴일없을것같지만,,)
	//head 포인터가 가리키는 곳에 ft_db_lstadd_front하기
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

// t_node	*ft_pop(t_node **head, unsigned int index) //고쳐.. 인덱스꺼 꺼내
// {
// 	t_node	*target;
// 	int		res;

// 	//빈 리스트 예외처리
// 	if (!*head || !(*head)->next)
// 		return (NULL); //->pop실행안함 -> strjoin 실행x 예외처리
// 	target = *head;
// 	//두번째 리스트를 꺼낸..노우
// 	while (target->next && index--)
// 		target = target->next;
// 	if (!target->next) //??
// 		return (NULL);
// 	res = target->data;
// 	ft_db_lstdelone(target);
// 	target = ft_db_lstnew(res);
// 	return (target);
// }


t_node	*ft_pop(t_node **where, unsigned int index)
{
	t_node	*target;
	int		res;

	target = *where;
	if (!*where)
		return (NULL);
	if ((*where)->type == 0)
	{
		while (target->next && index--)
			target = target->next;
		// if (!temp->next)
		// 	return (NULL);
	}
	else if ((*where)->type == 2)
	{
		while (target->prev && index--)
			target = target->prev;
		// if (!temp->prev)
		// 	return (NULL);
	}
	else
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
	else
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
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		popped = ft_pop(&stacks->stack_b, 1);
		if (ft_push(&stacks->stack_a, popped))
			res = "pa\n";
	}
	else if (a_or_b == 'b')
	{
		popped = ft_pop(&stacks->stack_a, 1);
		if (ft_push(&stacks->stack_b, popped))
			res = "pb\n";
	}
	return (res);
}

char	*rotater(t_stack *stacks, char a_or_b)
{
	t_node	*popped;
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		popped = ft_pop(&stacks->stack_a, 1);
		if (ft_push(&stacks->tail_a, popped))
			res = "ra\n";
	}
	else if (a_or_b == 'b')
	{
		popped = ft_pop(&stacks->stack_b, 1);
		if (ft_push(&stacks->tail_b, popped))
			res = "rb\n";
	}
	return (res);
}

char	*rev_rotater(t_stack *stacks, char a_or_b)
{
	t_node	*popped;
	char	*res;

	res = NULL;
	if (a_or_b == 'a')
	{
		popped = ft_pop(&stacks->tail_a, 1);
		if (ft_push(&stacks->stack_a, popped))
			res = "rra\n";
	}
	else if (a_or_b == 'b')
	{
		popped = ft_pop(&stacks->tail_b, 1);
		if (ft_push(&stacks->stack_b, popped))
			res = "rrb\n";
	}
	return (res);
}



/* sa, sb, ss */

/* pa, pb */

/* ra, rb, rr, rra, rrb, rrr */
