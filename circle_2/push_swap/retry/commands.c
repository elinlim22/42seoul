/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeslim <hyeslim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:07:48 by hyeslim           #+#    #+#             */
/*   Updated: 2022/10/25 19:32:24 by hyeslim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 단축 : sa+sa, sb+sb, ss+ss, pa+pb, pb+pa, ra+rra, rb+rrb, rr+rrr */

/* push & pop 구현 */
void	ft_push(t_node **head, t_node *node)
{
	//전체 자료 숫자 이상 넘어갈 시 오버플로우 예외처리(그럴일없을것같지만,,)
	//head 포인터가 가리키는 곳에 ft_db_lstadd_front하기
	ft_db_lstadd_front(&head, node);
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

char	*swap(t_node *head, int which)
{
	t_node	*temp;

	temp = ft_pop(&head);
	if (!temp)
		return (NULL);
	ft_push(&head, temp);
	return ("s");
}

void	sa(t_node **head, )










/* sa, sb, ss */

/* pa, pb */

/* ra, rb, rr, rra, rrb, rrr */
