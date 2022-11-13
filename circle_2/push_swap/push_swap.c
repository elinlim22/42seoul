// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   push_swap.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hyeslim <hyeslim@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/26 14:15:29 by hyeslim           #+#    #+#             */
// /*   Updated: 2022/10/17 14:48:38 by hyeslim          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack, int count);
int	set_chunk(int count);

int	set_chunk(int count)
{
	if (count < 30)
		return (5);
	if (count < 100)
		return (15);
	if (count < 500)
		return (30);
	if (count < 1000)
		return (45);
	if (count < 2000)
		return (65);
	if (count < 5000)
		return (150);
	else
		return (200);
}

void	push_swap(t_stack *stack, int count)
{
	int	chunk;
	int	i;
	static int	size;
	t_node	*curr;

	chunk = set_chunk(count);
	i = 0;
	size = count;
	curr = stack->stack_a->next;
	if (curr->type != 1)
		return ;
	// stack->index = indexing(arr, size);
	while (curr->type == 1)
	{
		while (i + chunk < count)
		{
			if (curr->data <= stack->index[i])
				pusher(stack, 'b');
			else if (stack->index[i] < curr->data && curr->data <= stack->index[i + chunk])
			{
				pusher(stack, 'b');
				rotater(stack, 'b');
			}
			else
				rotater(stack, 'a');
			i++;
		}
		curr = curr->next; //curr가 free되어버리면 어떻게 탐색하지?
		free(stack->index);
	}
	push_swap(stack, size);
}

// /* 전처리 ::: 끝!
// 	1. 인자값이 정수가 아닐때
// 	2. 인자값이 정수보다 클때
// 	3. 중복된 인자가 있을때
// 	4. 인자가 없을때
// 	5. 인자가 1개이거나 이미 정렬되었을때는 종료
// */

// /* 인자 받아와서 인덱싱 처리 */

// /* 양방향 연결리스트 사용
// 	스택 A와 스택 B를 각각 구조체로 만들어서 left/right 이동이 가능하도록 설계()
// 	각 스택에서 up/down으로 이동이 가능하도록 설계
// 	각 인자마다 인덱스값을 넣을 int
// */

// /* 함수 리스트
// 	1. 명령어 함수
// */

// 	인자 전처리&인덱싱하기
// 		복사본을 만들고 원본과 대조하면서 원본에 인덱싱 처리를 한다
// 	5개 미만일때 정렬
// 		5개일 때 -> 4개 솔팅 함수로 빠진다
// 		4개일때 -> 3개 솔팅함수로 빠진다
// 		3개일때 하드코딩
// 		재귀로 복귀하면서
// 	make b
// 		모래시계 모양으로 만든다
// 			가장 작은값을 먼저 넘긴다
// 	find max
// 		가장 큰 값을 찾아서 에이로 넘긴다
// 		i++;
// 	move to a
// 	명령어 출력
